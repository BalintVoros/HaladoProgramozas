#include "dailydata.h"

DailyData::DailyData()
{
}

DailyData::DailyData(const string &cityName, int numberOfSales, int totalSaleValue):
	cityName(cityName),
	numberOfSales(numberOfSales),
	totalSaleValue(totalSaleValue)
{
}

string DailyData::getCityName() const
{
	return cityName;
}

int DailyData::getNumberOfSales() const
{
	return numberOfSales;
}

int DailyData::getTotalSaleValue() const
{
	return totalSaleValue;
}

void DailyData::setCityName(const string &newCityName)
{
	cityName = newCityName;
}

void DailyData::setNumberOfSales(int newNumberOfSales)
{
	numberOfSales = newNumberOfSales;
}

void DailyData::setTotalSaleValue(int newTotalSaleValue)
{
	totalSaleValue = newTotalSaleValue;
}

ostream &operator<<(ostream &os, const DailyData &data)
{
	os << "At " << data.cityName << " had " << data.numberOfSales << " sales with a total value of " << data.totalSaleValue;
	return os;
}
