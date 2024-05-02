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
using namespace std;

#include "tarsasjatek.h"

class Handler
{
    SAConnection dbcon;
public:
    Handler()=default;
    void csatlakozas (const string& sqlite_fajl);
    void teszt ();

    // ezzel nincs teendo!
    // lefuttat egy parancsot, a kiveteleket kezeli
    // 'Trial version exception' eseten ujra probalkozik
    static void futtatBiztos (std::function<void(void)> taszk);

    // Ide johetnek a ZH feladat megoldasai:
    // ...
     vector<Tarsasjatek> betoltes();
    void ujJatek(const Tarsasjatek& jatek);
     void rosszakatTorol(float minErtekeles);
     void hosszModosit(const string& jatekNev, int ujHossz);
     list<Tarsasjatek> mitJatszunk(int maxHossz, int minJatekosszam);
};

#endif // HANDLER_H
