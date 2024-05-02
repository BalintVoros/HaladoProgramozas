#ifndef CREDITCARD_H
#define CREDITCARD_H

#include<iostream>
#include<string>

using namespace std;

class CreditCard
{
private:
	string card_number;
	string card_type;
	string currency;
	int balance;
public:
	CreditCard();
	CreditCard(const string& cn, const string& ct, const string& c, int b);

	const string& getCardNumber() const;
	const string& getCardType() const;
	const string& getCurrency() const;
	int getBalance() const;

	friend ostream& operator<<(ostream& os, const CreditCard& cc) {
		os << cc.card_number << " (" << cc.card_type << ") - " << cc.balance << " " << cc.currency;
		return os;
	}
};

#endif // CREDITCARD_H
