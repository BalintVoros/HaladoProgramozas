#ifndef CARDMANAGER_H
#define CARDMANAGER_H

#include<vector>
#include<list>
#include<set>
#include<algorithm>
#include<numeric>
#include <stdexcept> 
#include <list>

#include "creditcard.h"

using namespace std;

class CardManager
{
private:
	vector<CreditCard> cards;
public:
	CardManager(const vector<CreditCard>& c);

	const string& maxBalance() const;

	CreditCard find(const string& cn) const;

	int sumByCurrency(const string& c) const;

	list<string> cardNumbers() const;

	int countByType(const string& type) const;

	bool cardExistsWithHigherBalance(int balance) const;

	void printLowBalances() const;

	list<string> cardTypes() const;
};

#endif // CARDMANAGER_H
