#include <iostream>
#include <fstream>
#include <string>

#include "tarsasjatek.h"
#include "handler.h"

#define PART1  // 1.:   betolt()
#define PART2  // 2.:   kiadokListaz(), jatekokListaz()
#define PART3  // 3.:   clear()
#define PART4  // 4.:   kiadokJatekai()
#define PART5  // 5.:   nevsorrendben()
#define PART6  // 6.:   legtobbJatekosKiado()
#define PART7  // 7.:   atlagErtekeles()
#define PART7a // 7/a.: atlagErtekeles() kivetelkezelessel
#define PART8  // 8.:   komplexitasKeres()
#define PART9  // 9.:   felvasarol()
#define PART9a // 9/a.: felvasarol() torlessel

int main()
{
    cout << "main() eleje!" << endl << endl;

	const string db_hasznalt = "tarsasok.sqlite";
	const string db_eredeti = "tarsasok-eredeti.sqlite";
    {
        std::ifstream be(db_eredeti, std::ios::binary);
        if (!be.is_open())
        {
            cout << "Hiba! Nem sikerult megnyitni: " << db_eredeti << endl;
            cout << "(Jo helyre lett masolva a fajl?)" << endl << endl;
            return 1;
        }
        std::ofstream ki(db_hasznalt, std::ios::binary);
        if (!ki.is_open())
        {
            cout << "Hiba! Nem sikerult irasra megnyitni: " << db_hasznalt << endl;
            cout << "Az adatbazis igy nem all keszen a munkara." << endl << endl;
            return 1;
        }
        ki << be.rdbuf();
        be.close();
        ki.close();
    }

    Handler h;
    {
        cout << "Adatbazis teszt" << endl << endl;
        Handler::futtatBiztos([&](){
            h.csatlakozas(db_hasznalt);
            h.teszt();

        });
    }
    // (...egyeb szoveg...)
	// Rekordok szama: 21
    // Jo munkat!

	{
#ifdef PART1
		cout << endl << "1-3. feladat - alapok teszt" << endl << endl;
#endif // #ifdef PART1
        Handler::futtatBiztos([&](){
#ifdef PART1
            h.betolt();
#endif // #ifdef PART1
#ifdef PART2
			h.kiadokListaz();
			h.jatekokListaz();
#endif // #ifdef PART2
#ifdef PART3
			h.clear();
			h.kiadokListaz();
			h.jatekokListaz();
#endif // #ifdef PART3
        });
	}

#ifdef PART4
    {
		cout << endl << "4. feladat - kiadokJatekai() teszt" << endl << endl;
		Handler::futtatBiztos([&](){
            h.betolt();
			auto kiadoSzerint = h.kiadokJatekai();
			for (const auto &p : kiadoSzerint)
			{
				cout << p.first->getNev() << " jatekai:" << endl;
				for (const auto &j : p.second)
					cout << "  " << *j << endl;
			}
        });
	}
#endif // #ifdef PART4

#ifdef PART5
	{
		cout << endl << "5. feladat - nevsorrendben() teszt" << endl << endl;
		Handler::futtatBiztos([&](){
            h.betolt();
			auto nevsor = h.nevsorrendben();
			for (const auto &s : nevsor)
				cout << s << endl;
		});
	}
#endif // #ifdef PART5

#ifdef PART6
	{
		cout << endl << "6. feladat - legtobbJatekosKiado() teszt" << endl << endl;
		Handler::futtatBiztos([&](){
            h.betolt();
			Kiado * legtobbJatek = h.legtobbJatekosKiado();
			cout << "A legtobb jatekos kiado: " << legtobbJatek->getNev() << endl;
		});
	}
#endif // #ifdef PART6

#ifdef PART7
	{
		cout << endl << "7. feladat - atlagErtekeles() teszt" << endl << endl;
		Handler::futtatBiztos([&](){
            h.betolt();
			for (const string nev : {"Mindclash Games", "Days of Wonder"})
			{
				cout << nev << " atlagos ertekelese: " << h.atlagErtekeles(nev) << endl ;
			}
		});
	}
#endif // #ifdef PART7

#ifdef PART7a
	{
		cout << endl << "7/a. feladat - atlagErtekeles() kivetellel teszt" << endl << endl;
		Handler::futtatBiztos([&](){
            h.betolt();
			for (const string nev : {"Czech Games Edition", "Z-Man Games", "Cogitate Games", "2F Spiele", "Fantasy Flight Games"})
			{
				try{
					double atlag = h.atlagErtekeles(nev);
					cout << nev << " atlagos ertekelese: " << atlag << endl ;
				}
				catch(exception &e)
				{
					cout << "standard exception: " << e.what() << endl;
				}
				catch(...)
				{
					cout << "other exception" << endl;
				}
			}
		});
	}
#endif // #ifdef PART7a

#ifdef PART8
	{
		cout << endl << "8. feladat - komplexitasKeres() teszt" << endl << endl;
		Handler::futtatBiztos([&](){
            h.betolt();
			auto lista = h.komplexitasKeres(3.0,4.0);
			cout << "3.0 es 4.0 komplexitas kozotti jatekok:" << endl;
			for (Tarsasjatek *jatek : lista)
				cout << *jatek << endl;
		});
	}
#endif // #ifdef PART8

	{
#ifdef PART9
		cout << endl << "9-9/a. feladat - felvasarol() teszt" << endl << endl;
#endif // #ifdef PART9
		Handler::futtatBiztos([&](){
#ifdef PART9
			h.betolt();
			h.felvasarol("Fantasy Flight Games", "Days of Wonder");
            h.betolt();
			h.jatekokListaz();
#endif // #ifdef PART9
#ifdef PART9a
			h.kiadokListaz();
#endif // #ifdef PART9a
		});
	}

	cout << endl << "main() vege!" << endl;
    return 0;
}
