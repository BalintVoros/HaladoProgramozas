#include <iostream>
#include <fstream>
#include <string>

#include "tarsasjatek.h"
#include "handler.h"

#define PART1 // 1.: betoltes()
#define PART2 // 2.: ujJatek()
#define PART3 // 3.: rosszakatTorol()
#define PART4 // 4.: hosszModosit()
#define PART5 // 5.: mitJatszunk()

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

#ifdef PART1
    {
		cout << endl << "1. feladat - betoltes() teszt" << endl << endl;
        Handler::futtatBiztos([&](){
			vector<Tarsasjatek> mindenJatek = h.betoltes();
			cout << "Jatekok szama: " << mindenJatek.size() << endl;
			for (const Tarsasjatek &jatek : mindenJatek)
				cout << jatek << endl;
        });
    }
	//	Jatekok szama: 21
	//	Grand Dog Park (6.6) -- 6 fo, 30 perc, komplexitas: 1.33
	//	Secrets of the Lost Tomb (7.3) -- 6 fo, 120 perc, komplexitas: 3.19
	//	Not Alone (7) -- 7 fo, 45 perc, komplexitas: 2
	//	Black Gold (6.8) -- 5 fo, 120 perc, komplexitas: 2.59
	//	Photosynthesis (7) -- 4 fo, 60 perc, komplexitas: 2.26
	//	Star Realms (7.6) -- 2 fo, 20 perc, komplexitas: 1.93
	//	Saboteur (6.5) -- 10 fo, 30 perc, komplexitas: 1.32
	//	Voidfall (8.7) -- 4 fo, 240 perc, komplexitas: 4.58
	//	Forestaurant (7.4) -- 5 fo, 45 perc, komplexitas: 2.4
	//	Tikal (7.3) -- 4 fo, 90 perc, komplexitas: 2.78
	//	Mombasa (7.9) -- 4 fo, 150 perc, komplexitas: 3.9
	//	Petrichor (6.9) -- 4 fo, 80 perc, komplexitas: 3.01
	//	Battles of Westeros (7.2) -- 2 fo, 120 perc, komplexitas: 3.22
	//	For Sale (7.2) -- 6 fo, 30 perc, komplexitas: 1.25
	//	Power Grid (7.8) -- 6 fo, 120 perc, komplexitas: 3.26
	//	Century: Spice Road (7.3) -- 5 fo, 45 perc, komplexitas: 1.8
	//	Tawantinsuyu: The Inca Empire (7.4) -- 4 fo, 120 perc, komplexitas: 4.1
	//	Great Western Trail (8.2) -- 4 fo, 150 perc, komplexitas: 3.7
	//	Praetor (6.6) -- 5 fo, 75 perc, komplexitas: 3
	//	Zombicide: Black Plague (7.6) -- 6 fo, 180 perc, komplexitas: 2.49
	//	Bargain Hunter (6.7) -- 4 fo, 45 perc, komplexitas: 1.87
#endif // #ifdef PART1

#ifdef PART2
    {
		cout << endl << "2. feladat - ujJatek() teszt" << endl << endl;
        Handler::futtatBiztos([&](){
			Tarsasjatek jatek("Nusfjord", 2.84, 7.6, 100, 5);
			h.ujJatek(jatek);
			vector<Tarsasjatek> mindenJatek = h.betoltes();
			cout << "Jatekok szama: " << mindenJatek.size() << endl;
			for (const Tarsasjatek &jatek : mindenJatek)
				cout << jatek << endl;
        });
    }
	//	Jatekok szama: 22
	//	Grand Dog Park (6.6) -- 6 fo, 30 perc, komplexitas: 1.33
	//	Secrets of the Lost Tomb (7.3) -- 6 fo, 120 perc, komplexitas: 3.19
	//	Not Alone (7) -- 7 fo, 45 perc, komplexitas: 2
	//	Black Gold (6.8) -- 5 fo, 120 perc, komplexitas: 2.59
	//	Photosynthesis (7) -- 4 fo, 60 perc, komplexitas: 2.26
	//	Star Realms (7.6) -- 2 fo, 20 perc, komplexitas: 1.93
	//	Saboteur (6.5) -- 10 fo, 30 perc, komplexitas: 1.32
	//	Voidfall (8.7) -- 4 fo, 240 perc, komplexitas: 4.58
	//	Forestaurant (7.4) -- 5 fo, 45 perc, komplexitas: 2.4
	//	Tikal (7.3) -- 4 fo, 90 perc, komplexitas: 2.78
	//	Mombasa (7.9) -- 4 fo, 150 perc, komplexitas: 3.9
	//	Petrichor (6.9) -- 4 fo, 80 perc, komplexitas: 3.01
	//	Battles of Westeros (7.2) -- 2 fo, 120 perc, komplexitas: 3.22
	//	For Sale (7.2) -- 6 fo, 30 perc, komplexitas: 1.25
	//	Power Grid (7.8) -- 6 fo, 120 perc, komplexitas: 3.26
	//	Century: Spice Road (7.3) -- 5 fo, 45 perc, komplexitas: 1.8
	//	Tawantinsuyu: The Inca Empire (7.4) -- 4 fo, 120 perc, komplexitas: 4.1
	//	Great Western Trail (8.2) -- 4 fo, 150 perc, komplexitas: 3.7
	//	Praetor (6.6) -- 5 fo, 75 perc, komplexitas: 3
	//	Zombicide: Black Plague (7.6) -- 6 fo, 180 perc, komplexitas: 2.49
	//	Bargain Hunter (6.7) -- 4 fo, 45 perc, komplexitas: 1.87
	//	Nusfjord (7.6) -- 5 fo, 100 perc, komplexitas: 2.84
#endif // #ifdef PART2

#ifdef PART3
    {
		cout << endl << "3. feladat - rosszakatTorol() teszt" << endl << endl;
        Handler::futtatBiztos([&](){
			h.rosszakatTorol(6.99);
			vector<Tarsasjatek> mindenJatek = h.betoltes();
			cout << "Jatekok szama: " << mindenJatek.size() << endl;
			for (const Tarsasjatek &jatek : mindenJatek)
				cout << jatek << endl;
        });
    }
	//	Jatekok szama: 16
	//	Secrets of the Lost Tomb (7.3) -- 6 fo, 120 perc, komplexitas: 3.19
	//	Not Alone (7) -- 7 fo, 45 perc, komplexitas: 2
	//	Photosynthesis (7) -- 4 fo, 60 perc, komplexitas: 2.26
	//	Star Realms (7.6) -- 2 fo, 20 perc, komplexitas: 1.93
	//	Voidfall (8.7) -- 4 fo, 240 perc, komplexitas: 4.58
	//	Forestaurant (7.4) -- 5 fo, 45 perc, komplexitas: 2.4
	//	Tikal (7.3) -- 4 fo, 90 perc, komplexitas: 2.78
	//	Mombasa (7.9) -- 4 fo, 150 perc, komplexitas: 3.9
	//	Battles of Westeros (7.2) -- 2 fo, 120 perc, komplexitas: 3.22
	//	For Sale (7.2) -- 6 fo, 30 perc, komplexitas: 1.25
	//	Power Grid (7.8) -- 6 fo, 120 perc, komplexitas: 3.26
	//	Century: Spice Road (7.3) -- 5 fo, 45 perc, komplexitas: 1.8
	//	Tawantinsuyu: The Inca Empire (7.4) -- 4 fo, 120 perc, komplexitas: 4.1
	//	Great Western Trail (8.2) -- 4 fo, 150 perc, komplexitas: 3.7
	//	Zombicide: Black Plague (7.6) -- 6 fo, 180 perc, komplexitas: 2.49
	//	Nusfjord (7.6) -- 5 fo, 100 perc, komplexitas: 2.84
#endif // #ifdef PART3

#ifdef PART4
    {
		cout << endl << "4. feladat - hosszModosit() teszt" << endl << endl;
        Handler::futtatBiztos([&](){
			h.hosszModosit("Great Western Trail", 180);
			h.hosszModosit("For Sale", 60);
			h.hosszModosit("Tikal", 50);
			vector<Tarsasjatek> mindenJatek = h.betoltes();
			cout << "Jatekok szama: " << mindenJatek.size() << endl;
			for (const Tarsasjatek &jatek : mindenJatek)
				cout << jatek << endl;
        });
    }
	//	Jatekok szama: 16
	//	Secrets of the Lost Tomb (7.3) -- 6 fo, 120 perc, komplexitas: 3.19
	//	Not Alone (7) -- 7 fo, 45 perc, komplexitas: 2
	//	Photosynthesis (7) -- 4 fo, 60 perc, komplexitas: 2.26
	//	Star Realms (7.6) -- 2 fo, 20 perc, komplexitas: 1.93
	//	Voidfall (8.7) -- 4 fo, 240 perc, komplexitas: 4.58
	//	Forestaurant (7.4) -- 5 fo, 45 perc, komplexitas: 2.4
	//	Tikal (7.3) -- 4 fo, 50 perc, komplexitas: 2.78
	//	Mombasa (7.9) -- 4 fo, 150 perc, komplexitas: 3.9
	//	Battles of Westeros (7.2) -- 2 fo, 120 perc, komplexitas: 3.22
	//	For Sale (7.2) -- 6 fo, 60 perc, komplexitas: 1.25
	//	Power Grid (7.8) -- 6 fo, 120 perc, komplexitas: 3.26
	//	Century: Spice Road (7.3) -- 5 fo, 45 perc, komplexitas: 1.8
	//	Tawantinsuyu: The Inca Empire (7.4) -- 4 fo, 120 perc, komplexitas: 4.1
	//	Great Western Trail (8.2) -- 4 fo, 180 perc, komplexitas: 3.7
	//	Zombicide: Black Plague (7.6) -- 6 fo, 180 perc, komplexitas: 2.49
	//	Nusfjord (7.6) -- 5 fo, 100 perc, komplexitas: 2.84
#endif // #ifdef PART4

#ifdef PART5
    {
		cout << endl << "5. feladat - mitJatszunk() teszt" << endl << endl;
        Handler::futtatBiztos([&](){
			list<Tarsasjatek> opciok = h.mitJatszunk(100, 5);
			cout << "Lehetosegek szama: " << opciok.size() << endl;
			for (const Tarsasjatek &jatek : opciok)
				cout << jatek << endl;
        });
    }
	//	Lehetosegek szama: 5
	//	Nusfjord (7.6) -- 5 fo, 100 perc, komplexitas: 2.84
	//	Forestaurant (7.4) -- 5 fo, 45 perc, komplexitas: 2.4
	//	Century: Spice Road (7.3) -- 5 fo, 45 perc, komplexitas: 1.8
	//	For Sale (7.2) -- 6 fo, 60 perc, komplexitas: 1.25
	//	Not Alone (7) -- 7 fo, 45 perc, komplexitas: 2
#endif // #ifdef PART5

	cout << endl << "main() vege!" << endl;
    return 0;
}
