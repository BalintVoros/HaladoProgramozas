#ifndef HANDLER_H
#define HANDLER_H

#include <SQLAPI.h>

#include <iostream>
#include <list>
#include <vector>
#include <map>
#include <algorithm>
#include <numeric>
#include <functional>
#include <exception>
using namespace std;

#include "tarsasjatek.h"


class Handler
{
    SAConnection dbcon;
    list<Kiado*> kiadok;
    list<Tarsasjatek*> tarsasjatekok;
	// Ide johetnek az adattagok:
	// ...


public:
    Handler()=default;
    void csatlakozas (const string& sqlite_fajl);
    void teszt ();


    static void futtatBiztos (function<void(void)> taszk);
    void clear();
    void betolt();

     void betoltKiadok();
     void betoltTarsasjatekok();
     Kiado* keresKiadot(int kiadoId);
     void kiadokListaz() const;
     void jatekokListaz() const;
    map<Kiado*, list<Tarsasjatek*>> kiadokJatekai() const;
     list<string> nevsorrendben() const;
     Kiado* legtobbJatekosKiado() const;
     double atlagErtekeles(const std::string& kiadoNev) const;
     list<Tarsasjatek*> komplexitasKeres(double alsoKomplexitas, double felsoKomplexitas) const;
     void felvasarol(const std::string& felvasarloKiadoNev, const std::string& felvasaroltKiadoNev);
    // Ide johetnek a ZH feladat megoldasai:
	// ...
};

#endif // HANDLER_H
