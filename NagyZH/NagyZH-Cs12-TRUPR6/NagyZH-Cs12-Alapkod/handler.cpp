#include "handler.h"
#include <numeric>
#include <stdexcept>
#include <string>
#include <algorithm>
#include <map>
#include "KiadoNemTalalhato.h"


void Handler::csatlakozas(const string &fajl)
{
    dbcon.Connect(fajl.c_str(),"","",SA_SQLite_Client);
}

void Handler::teszt()
{
	SACommand szamol(&dbcon,"SELECT count(id) FROM tarsasok");
    szamol.Execute();
    szamol.FetchNext();
    int cnt = szamol[1].asLong();
    cout << "Rekordok szama: " << cnt << endl;
    cout << "Jo munkat!" << endl << endl;
}

// ezzel nincs teendo!
// lefuttat egy parancsot, a kiveteleket kezeli
// 'Trial version exception' eseten ujra probalkozik
#include <thread>
#include <chrono>
#include <random>

void Handler::futtatBiztos(std::function<void()> taszk)
{
    std::mt19937_64 rgen(12345678);
    while (true)
    {
        try {
            taszk();
        }
        catch (const SAException& exc)
        {
            string msg = exc.ErrText().GetMultiByteChars();
            if (msg.find("Trial version exception") != string::npos)
            {
                cout << "'Trial version exception' hiba tortent!" << endl;
                int k = 1000+rgen()%200;
                cout << "Ujraprobalkozas " << k << " ms mulva..." << endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(k));
                continue;
            }
            else
            {
                cout << "SAException:" << endl;
                cout << msg << endl;
            }
        }
        catch (...)
        {
            cout << "Egyeb (nem SAException) tipusu exception!" << endl;
        }
        break;
	}
}
void Handler::betolt() {
     clear();
    dbcon.Connect("tarsasok-eredeti.sqlite", "", "", SA_SQLite_Client);
    betoltKiadok();
    betoltTarsasjatekok();
}
void Handler::betoltKiadok() {
    SACommand select(&dbcon, "SELECT * FROM kiadok");
    select.Execute();
    while (select.FetchNext()) {
        int id = select[1].asLong();
        std::string nev = select[2].asString().GetMultiByteChars();
        std::string telephely = select[3].asString().GetMultiByteChars();
        int alapitva = select[4].asLong();

        Kiado* ujKiado = new Kiado(id, nev, telephely, alapitva);
        kiadok.push_back(ujKiado);
    }
}
void Handler::betoltTarsasjatekok() {
    SACommand select(&dbcon, "SELECT * FROM tarsasok");
    select.Execute();
    while (select.FetchNext()) {
        int id = select[1].asLong();
        std::string nev = select[2].asString().GetMultiByteChars();
        double nehezseg = select[3].asDouble();
        double ertekeles = select[4].asDouble();
        int hossz = select[5].asLong();
        int jatekosszam = select[6].asLong();
        int kiadoId = select[7].asLong();

        Kiado* kiadoPtr = nullptr;
        for (auto kiado : kiadok) {
            if (kiado->getId() == kiadoId) {
                kiadoPtr = kiado;
                break;
            }
        }

        Tarsasjatek* ujJatek = new Tarsasjatek(id, nev, nehezseg, ertekeles, hossz, jatekosszam, kiadoPtr);
        tarsasjatekok.push_back(ujJatek);
    }
}
Kiado* Handler::keresKiadot(int kiadoId) {
    for (auto kiado : kiadok) {
        if (kiado->getId() == kiadoId) {
            return kiado;
        }
    }
    return nullptr;
}
void Handler::kiadokListaz() const {
    std::cout << "Kiadok: " << std::endl;
    for (const auto& kiado : kiadok) {
        std::cout << *kiado << std::endl;
    }
}

void Handler::jatekokListaz() const {
    std::cout << "Jatekok: " << std::endl;
    for (const auto& jatek : tarsasjatekok) {
        std::cout << *jatek << std::endl;
    }
}
void Handler::clear() {
    for (auto kiado : kiadok) {
        delete kiado;
    }
    kiadok.clear();

    for (auto jatek : tarsasjatekok) {
        delete jatek;
    }
    tarsasjatekok.clear();
}
std::map<Kiado*, std::list<Tarsasjatek*>> Handler::kiadokJatekai() const {
    std::map<Kiado*, std::list<Tarsasjatek*>> kiadoJatekok;
    for (const auto& jatek : tarsasjatekok) {
        Kiado* kiado = jatek->getKiado();
        kiadoJatekok[kiado].push_back(jatek);
    }
    return kiadoJatekok;
}
std::list<std::string> Handler::nevsorrendben() const {
    std::list<std::string> nevek;


    std::transform(tarsasjatekok.begin(), tarsasjatekok.end(), std::back_inserter(nevek),
                   [](const Tarsasjatek* jatek) { return jatek->getNev(); });


    nevek.sort();

    return nevek;
}

Kiado* Handler::legtobbJatekosKiado() const {
    std::map<Kiado*, int> kiadoJatekokSzama;

    for (const auto& jatek : tarsasjatekok) {
        kiadoJatekokSzama[jatek->getKiado()]++;
    }

    auto legtobbJatekos = std::max_element(kiadoJatekokSzama.begin(), kiadoJatekokSzama.end(),
                                           [](const std::pair<Kiado* const, int>& a, const std::pair<Kiado* const, int>& b) {
                                               return a.second < b.second;
                                           });

    return legtobbJatekos != kiadoJatekokSzama.end() ? legtobbJatekos->first : nullptr;
}
double Handler::atlagErtekeles(const std::string& kiadoNev) const {
    double osszesErtekeles = 0.0;
    int jatekokSzama = 0;

    for (const auto& jatek : tarsasjatekok) {
        if (jatek->getKiado()->getNev() == kiadoNev) {
            osszesErtekeles += jatek->getErtekeles();
            ++jatekokSzama;
        }
    }

    if (jatekokSzama == 0) {
        throw KiadoNemTalalhato(kiadoNev);
    }

    return osszesErtekeles / jatekokSzama;
}
std::list<Tarsasjatek*> Handler::komplexitasKeres(double alsoKomplexitas, double felsoKomplexitas) const {
    std::list<Tarsasjatek*> eredmeny;


    std::copy_if(tarsasjatekok.begin(), tarsasjatekok.end(), std::back_inserter(eredmeny),
                 [alsoKomplexitas, felsoKomplexitas](const Tarsasjatek* jatek) {
                     return jatek->getNehezseg() >= alsoKomplexitas && jatek->getNehezseg() <= felsoKomplexitas;
                 });


    eredmeny.sort([](const Tarsasjatek* a, const Tarsasjatek* b) {
        return a->getErtekeles() > b->getErtekeles();
    });

    return eredmeny;
}
void Handler::felvasarol(const std::string& felvasarloKiadoNev, const std::string& felvasaroltKiadoNev) {

    int felvasarloKiadoId = -1;
    int felvasaroltKiadoId = -1;

    SACommand select(&dbcon);
    select.setCommandText("SELECT id FROM kiadok WHERE nev = :kiadoNev");
    select.Param("kiadoNev").setAsString() = felvasarloKiadoNev.c_str();
    select.Execute();
    if (select.FetchNext()) {
        felvasarloKiadoId = select[1].asLong();
    } else {
        throw std::runtime_error("Felvasarlo kiado nem talalhato: " + felvasarloKiadoNev);
    }

    select.Param("kiadoNev").setAsString() = felvasaroltKiadoNev.c_str();
    select.Execute();
    if (select.FetchNext()) {
        felvasaroltKiadoId = select[1].asLong();
    } else {
        throw std::runtime_error("Felvasarolt kiado nem talalhato: " + felvasaroltKiadoNev);
    }

    SACommand update(&dbcon);
    update.setCommandText("UPDATE tarsasok SET kiadoId = :felvasarloKiadoId WHERE kiadoId = :felvasaroltKiadoId");
    update.Param("felvasarloKiadoId").setAsLong() = felvasarloKiadoId;
    update.Param("felvasaroltKiadoId").setAsLong() = felvasaroltKiadoId;
    update.Execute();


    SACommand deleteCmd(&dbcon);
    deleteCmd.setCommandText("DELETE FROM kiadok WHERE id = :felvasaroltKiadoId");
    deleteCmd.Param("felvasaroltKiadoId").setAsLong() = felvasaroltKiadoId;
    deleteCmd.Execute();
}
