#include "cardmanager.h"

CardManager::CardManager(const vector<CreditCard>& c) : cards(c) {}

const string& CardManager::maxBalance() const {
	
	auto maxBalanceCard = std::max_element(cards.begin(), cards.end(),
		[](const CreditCard& card1, const CreditCard& card2) {
			return card1.getBalance() < card2.getBalance();
		});

	
	if (maxBalanceCard != cards.end()) {
		
		return maxBalanceCard->getCardNumber();
	}
	else {
		
		return "";  
	}
}


CreditCard CardManager::find(const string& cn) const
{
	
	auto foundCard = std::find_if(cards.begin(), cards.end(),
		[&cn](const CreditCard& card) {
			return card.getCardNumber() == cn;
		});

	
	if (foundCard != cards.end()) {
		
		return *foundCard;
	}
	else {
		
		throw std::runtime_error("Card not found: " + cn);
		
	}
	return {};
}

int CardManager::sumByCurrency(const string& c) const
{
	
	int totalBalance = std::accumulate(cards.begin(), cards.end(), 0,
		[&c](int sum, const CreditCard& card) {
			return sum + (card.getCurrency() == c ? card.getBalance() : 0);
		});

	return totalBalance;
}

list<string> CardManager::cardNumbers() const
{
	
	list<string> cardNumberList;
	std::transform(cards.begin(), cards.end(), std::back_inserter(cardNumberList),
		[](const CreditCard& card) {
			return card.getCardNumber();
		});

	return cardNumberList;
}

int CardManager::countByType(const string& type) const
{
	
	int countOfType = std::count_if(cards.begin(), cards.end(),
		[&type](const CreditCard& card) {
			return card.getCardType() == type;
		});

	return countOfType;
}

bool CardManager::cardExistsWithHigherBalance(int balance) const
{
	
	return std::any_of(cards.begin(), cards.end(),
		[balance](const CreditCard& card) {
			return card.getBalance() > balance;
		});
}

void CardManager::printLowBalances() const
{
	std::vector<std::pair<const CreditCard*, int>> cardBalancePairs;
	std::transform(cards.begin(), cards.end(), std::back_inserter(cardBalancePairs),
		[](const CreditCard& card) {
			return std::make_pair(&card, card.getBalance());
		});

	
	std::sort(cardBalancePairs.begin(), cardBalancePairs.end(),
		[](const auto& lhs, const auto& rhs) {
			return lhs.second < rhs.second;
		});

	
	int count = 0;
	std::for_each(cardBalancePairs.begin(), cardBalancePairs.end(),
		[&count](const auto& pair) {
			if (count < 10) {
				std::cout << *pair.first << std::endl;
				count++;
			}
		});
}

list<string> CardManager::cardTypes() const
{
	list<string> allCardTypes;
	std::transform(cards.begin(), cards.end(), std::back_inserter(allCardTypes),
		[](const CreditCard& card) {
			return card.getCardType();
		});

	
	allCardTypes.sort();

	
	allCardTypes.erase(std::unique(allCardTypes.begin(), allCardTypes.end()), allCardTypes.end());

	return allCardTypes;
	
}
