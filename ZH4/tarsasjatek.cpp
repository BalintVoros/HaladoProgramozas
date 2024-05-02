#include "tarsasjatek.h"

Tarsasjatek::Tarsasjatek(const string &nev, double nehezseg, double ertekeles, int hossz, int jatekosszam):
	nev(nev),
	nehezseg(nehezseg),
	ertekeles(ertekeles),
	hossz(hossz),
	jatekosszam(jatekosszam)
{
}

string Tarsasjatek::getNev() const
{
	return nev;
}

void Tarsasjatek::setNev(const string &newNev)
{
	nev = newNev;
}

double Tarsasjatek::getNehezseg() const
{
	return nehezseg;
}

void Tarsasjatek::setNehezseg(double newNehezseg)
{
	nehezseg = newNehezseg;
}

double Tarsasjatek::getErtekeles() const
{
	return ertekeles;
}

void Tarsasjatek::setErtekeles(double newErtekeles)
{
	ertekeles = newErtekeles;
}

int Tarsasjatek::getHossz() const
{
	return hossz;
}

void Tarsasjatek::setHossz(int newHossz)
{
	hossz = newHossz;
}

int Tarsasjatek::getJatekosszam() const
{
	return jatekosszam;
}

void Tarsasjatek::setJatekosszam(int newJatekosszam)
{
	jatekosszam = newJatekosszam;
}

ostream &operator<<(ostream &os, const Tarsasjatek &jatek)
{
	os << jatek.nev << " (" << jatek.ertekeles << ") -- " << jatek.jatekosszam << " fo, " << jatek.hossz << " perc, komplexitas: " << jatek.nehezseg;
	return os;
}
