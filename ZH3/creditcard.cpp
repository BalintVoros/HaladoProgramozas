#include "creditcard.h"

CreditCard::CreditCard()
{
}

CreditCard::CreditCard(const string& cn, const string& ct, const string& c, int b)
	: card_number(cn), card_type(ct), currency(c), balance(b){}

const string& CreditCard::getCardNumber() const {
	return card_number;
}

const string& CreditCard::getCardType() const {
	return card_type;
}

const string& CreditCard::getCurrency() const {
	return currency;
}

int CreditCard::getBalance() const {
	return balance;
}