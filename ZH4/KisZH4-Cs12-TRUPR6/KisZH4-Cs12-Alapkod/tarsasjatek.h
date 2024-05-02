#ifndef TARSASJATEK_H
#define TARSASJATEK_H

#include <string>
#include <ostream>

using std::string;
using std::ostream;

class Tarsasjatek
{
	string nev;
	double nehezseg;
	double ertekeles;
	int hossz;
	int jatekosszam;
public:
	Tarsasjatek() = default;
	Tarsasjatek(const string &nev, double nehezseg, double ertekeles, int hossz, int jatekosszam);
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

	friend ostream &operator<<(ostream &os, const Tarsasjatek &jatek);
};

ostream &operator<<(ostream &os, const Tarsasjatek &jatek);

#endif // TARSASJATEK_H
