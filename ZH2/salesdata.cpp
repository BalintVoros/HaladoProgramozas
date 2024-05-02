#include "salesdata.h"
#include <iostream>

SalesData::SalesData(unsigned int size):
    dailySales(size)

{

}
void SalesData::setDailySale(unsigned int dayIndex, const DailyData &dailyData)
{
    if (dayIndex < dailySales.size())
    {
        dailySales[dayIndex] = dailyData;
    }
    else
    {
        while (dayIndex >= dailySales.size())
        {
            dailySales.push_back(DailyData());
        }
        dailySales[dayIndex] = dailyData;
    }
}
int SalesData::activeDays() const
{
    int activeDayCount = 0;

    for (const DailyData &daily : dailySales)
    {
        if (!daily.getCityName().empty())
        {
            activeDayCount++;
        }
    }

    return activeDayCount;
}
std::map<unsigned int, double> SalesData::getDailyAverage() const
{
    std::map<unsigned int, double> dailyAverage;

    for (unsigned int dayIndex = 0; dayIndex < dailySales.size(); dayIndex++)
    {
        const DailyData &daily = dailySales[dayIndex];

        if (!daily.getCityName().empty())
        {
            int totalSaleValue = daily.getTotalSaleValue();
            int numberOfSales = daily.getNumberOfSales();

            double average = static_cast<double>(totalSaleValue) / numberOfSales;

            dailyAverage[dayIndex] = average;
        }
    }

    return dailyAverage;
}
std::map<std::string, std::list<unsigned int>> SalesData::getCityVisits() const
{
    std::map<std::string, std::list<unsigned int>> cityVisits;

    for (unsigned int dayIndex = 0; dayIndex < dailySales.size(); dayIndex++)
    {
        const DailyData &daily = dailySales[dayIndex];
        const std::string cityName = daily.getCityName();

        if (!cityName.empty())
        {

            if (cityVisits.find(cityName) == cityVisits.end())
            {
                cityVisits[cityName] = std::list<unsigned int>();
            }

            cityVisits[cityName].push_back(dayIndex);
        }
    }

    return cityVisits;
}

void SalesData::listAllWhere(std::function<bool(const DailyData &)> predicate) const
{
    for (unsigned int dayIndex = 0; dayIndex < dailySales.size(); dayIndex++)
    {
        const DailyData &daily = dailySales[dayIndex];

        if (!daily.getCityName().empty() && predicate(daily))
        {
            std::cout << "Nap " << dayIndex << ": " << daily << std::endl;
        }
    }
}

