#ifndef TARSASJATEK_H
#define TARSASJATEK_H

#include <string>
#include <ostream>
#include "kiado.h"

using std::string;
using std::ostream;

class Tarsasjatek
{
	int id;
	string nev;
	double nehezseg;
	double ertekeles;
	int hossz;
	int jatekosszam;
	Kiado *kiado = nullptr;
public:
	Tarsasjatek() = default;
	Tarsasjatek(int id, const string &nev, double nehezseg, double ertekeles, int hossz, int jatekosszam, Kiado *kiado = nullptr);
	int getId() const;
	void setId(int newId);
	string getNev() const;
	void setNev(const string &newNev);
	double getNehezseg() const;
	void setNehezseg(double newNehezseg);
	double getErtekeles() const;
	void setErtekeles(double newErtekeles);
	int getHossz() const;
	void setHossz(int newHossz);
	int getJatekosszam() const;
	void setJatekosszam(int newJatekosszam);
	Kiado *getKiado() const;
	void setKiado(Kiado *newKiado);

	friend ostream &operator<<(ostream &os, const Tarsasjatek &jatek);
};

ostream &operator<<(ostream &os, const Tarsasjatek &jatek);

#endif // TARSASJATEK_H
