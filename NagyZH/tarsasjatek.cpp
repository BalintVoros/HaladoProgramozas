#include "tarsasjatek.h"

Tarsasjatek::Tarsasjatek(int id, const string &nev, double nehezseg, double ertekeles, int hossz, int jatekosszam, Kiado *kiado):
	id(id),
	nev(nev),
	nehezseg(nehezseg),
	ertekeles(ertekeles),
	hossz(hossz),
	jatekosszam(jatekosszam),
	kiado(kiado)
{
}

int Tarsasjatek::getId() const
{
	return id;
}

void Tarsasjatek::setId(int newId)
{
	id = newId;
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

Kiado *Tarsasjatek::getKiado() const
{
	return kiado;
}

void Tarsasjatek::setKiado(Kiado *newKiado)
{
	kiado = newKiado;
}

ostream &operator<<(ostream &os, const Tarsasjatek &jatek)
{
	os << jatek.nev << " (" << (jatek.kiado?jatek.kiado->getNev():"n/a") << ") -- " << jatek.jatekosszam << " fo, " << jatek.hossz << " perc, " << jatek.nehezseg << "/5, " << jatek.ertekeles << "/10";
	return os;
}
