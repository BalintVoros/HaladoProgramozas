#ifndef DAILYDATA_H
#define DAILYDATA_H

#include <string>
#include <ostream>

using namespace std;

class DailyData
{
	string cityName;
	int numberOfSales=0;
	int totalSaleValue=0;
public:
	DailyData();
	DailyData(const string &cityName, int numberOfSales, int totalSaleValue);
	string getCityName() const;
	int getNumberOfSales() const;
	int getTotalSaleValue() const;
	void setCityName(const string &newCityName);
	void setNumberOfSales(int newNumberOfSales);
	void setTotalSaleValue(int newTotalSaleValue);
	friend ostream &operator<<(ostream &os, const DailyData &data);
};

ostream &operator<<(ostream &os, const DailyData &data);

#endif // DAILYDATA_H
