#include "handler.h"

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

vector<Tarsasjatek> Handler::betoltes() {
    vector<Tarsasjatek> jatekok;

    SACommand select(&dbcon, _TSA("SELECT nev, nehezseg, ertekeles, hossz, jatekosszam FROM tarsasok"));
    select.Execute();

    while (select.FetchNext()) {
        string nev = select.Field("nev").asString().GetMultiByteChars();
        double nehezseg = select.Field("nehezseg").asDouble();
        double ertekeles = select.Field("ertekeles").asDouble();
        int hossz = select.Field("hossz").asInt64();
        int jatekosszam = select.Field("jatekosszam").asInt64();

        Tarsasjatek jatek(nev, nehezseg, ertekeles, hossz, jatekosszam);
        jatekok.push_back(jatek);
    }

    return jatekok;
}
void Handler::ujJatek(const Tarsasjatek& jatek) {
    SACommand insert(&dbcon);
    insert.setCommandText(_TSA("INSERT INTO tarsasok (nev, nehezseg, ertekeles, hossz, jatekosszam) VALUES (:1, :2, :3, :4, :5)"));
    insert.Param(1).setAsString() = _TSA(jatek.getNev().c_str());
    insert.Param(2).setAsDouble() = jatek.getNehezseg();
    insert.Param(3).setAsDouble() = jatek.getErtekeles();
    insert.Param(4).setAsInt64() = jatek.getHossz();
    insert.Param(5).setAsInt64() = jatek.getJatekosszam();

    insert.Execute();
}
void Handler::rosszakatTorol(float minErtekeles) {
    SACommand del(&dbcon);
    del.setCommandText(_TSA("DELETE FROM tarsasok WHERE ertekeles < :1"));
    del.Param(1).setAsDouble() = minErtekeles;

    del.Execute();
}
void Handler::hosszModosit(const string& jatekNev, int ujHossz) {
    SACommand update(&dbcon);
    update.setCommandText(_TSA("UPDATE tarsasok SET hossz = :1 WHERE nev = :2"));
    update.Param(1).setAsInt64() = ujHossz;
    update.Param(2).setAsString() = _TSA(jatekNev.c_str());

    update.Execute();
}
list<Tarsasjatek> Handler::mitJatszunk(int maxHossz, int minJatekosszam) {
    list<Tarsasjatek> jatekok;

    SACommand select(&dbcon);
    select.setCommandText(_TSA("SELECT nev, nehezseg, ertekeles, hossz, jatekosszam FROM tarsasok WHERE hossz <= :1 AND jatekosszam >= :2 ORDER BY ertekeles DESC"));
    select.Param(1).setAsInt64() = maxHossz;
    select.Param(2).setAsInt64() = minJatekosszam;

    select.Execute();

    while (select.FetchNext()) {
        string nev = select.Field("nev").asString().GetMultiByteChars();
        double nehezseg = select.Field("nehezseg").asDouble();
        double ertekeles = select.Field("ertekeles").asDouble();
        int hossz = select.Field("hossz").asInt64();
        int jatekosszam = select.Field("jatekosszam").asInt64();
        Tarsasjatek jatek(nev, nehezseg, ertekeles, hossz, jatekosszam);
        jatekok.push_back(jatek);
    }

    return jatekok;
}
