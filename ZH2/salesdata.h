#ifndef SALESDATA_H
#define SALESDATA_H

#include <vector>
#include <list>
#include <map>
#include <functional>
#include <map>
#include <list>

#include "dailydata.h"

class SalesData
{
	vector<DailyData> dailySales;
public:
	SalesData(unsigned size);


    void setDailySale(unsigned int dayIndex, const DailyData &dailyData);

    int activeDays() const;

    std::map<unsigned int, double> getDailyAverage() const;

    std::map<std::string, std::list<unsigned int>> getCityVisits() const;

     void listAllWhere(std::function<bool(const DailyData &)> predicate) const;

};

#endif // SALESDATA_H
