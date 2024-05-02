#ifndef KIADO_H
#define KIADO_H

#include <string>
#include <ostream>

using std::string;
using std::ostream;

class Kiado
{
	int id;
	string nev;
	string telephely;
	int alapitva;
public:
	Kiado() = default;
	Kiado(int id, const string &nev, const string &telephely, int alapitva);
	int getId() const;
	void setId(int newId);
	string getNev() const;
	void setNev(const string &newNev);
	string getTelephely() const;
	void setTelephely(const string &newTelephely);
	int getAlapitva() const;
	void setAlapitva(int newAlapitva);

	friend ostream &operator<<(ostream &os, const Kiado &k);
};

ostream &operator<<(ostream &os, const Kiado &k);

#endif // KIADO_H
