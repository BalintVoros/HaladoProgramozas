#include "kiado.h"

Kiado::Kiado(int id, const std::string &nev, const std::string &telephely, int alapitva):
	id(id),
	nev(nev),
	telephely(telephely),
	alapitva(alapitva)
{
}

int Kiado::getId() const
{
	return id;
}

void Kiado::setId(int newId)
{
	id = newId;
}

string Kiado::getNev() const
{
	return nev;
}

void Kiado::setNev(const string &newNev)
{
	nev = newNev;
}

string Kiado::getTelephely() const
{
	return telephely;
}

void Kiado::setTelephely(const string &newTelephely)
{
	telephely = newTelephely;
}

int Kiado::getAlapitva() const
{
	return alapitva;
}

void Kiado::setAlapitva(int newAlapitva)
{
	alapitva = newAlapitva;
}

ostream &operator<<(ostream &os, const Kiado &k)
{
	os << k.getNev() << ": in " << k.getTelephely() << " since " << k.getAlapitva();
	return os;
}
