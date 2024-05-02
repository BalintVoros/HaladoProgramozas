#include <iostream>
#include "salesdata.h"

using namespace std;

void fillSalesData(SalesData &sdata)
{
    sdata.setDailySale(5, DailyData("Veszprem", 14, 15000));
    sdata.setDailySale(12, DailyData("Gyor", 34, 250000));
    sdata.setDailySale(26, DailyData("Budapest", 21, 65000));
    sdata.setDailySale(29, DailyData("Szeged", 43, 432500));
    sdata.setDailySale(0, DailyData("Gyor", 12, 65000));
    sdata.setDailySale(9, DailyData("Szeged", 54, 321400));
    sdata.setDailySale(25, DailyData("Veszprem", 32, 65300));
    sdata.setDailySale(16, DailyData("Szeged", 32, 26800));
    sdata.setDailySale(19, DailyData("Budapest", 54, 543100));
    sdata.setDailySale(24, DailyData("Pecs", 12, 76400));
    sdata.setDailySale(2, DailyData("Pecs", 54, 124400));
    sdata.setDailySale(1, DailyData("Veszprem", 28, 32100));
    sdata.setDailySale(18, DailyData("Budapest", 28, 21400));
    sdata.setDailySale(22, DailyData("Nyiregyhaza", 18, 76100));
    sdata.setDailySale(27, DailyData("Debrecen", 19, 23700));
    sdata.setDailySale(17, DailyData("Veszprem", 23, 63200));
}

int main()
{
    {
        cout << endl << endl << "1. feladat" << endl;
        SalesData sdata(31);
        fillSalesData(sdata);
        cout << "Latszolag jo" << endl;
    }

    {
        cout << endl << endl << "2. feladat" << endl;
        SalesData sdata(31);
        fillSalesData(sdata);
        cout << sdata.activeDays() << endl;
    }

    {
        cout << endl << endl << "3. feladat" << endl;
        SalesData sdata(31);
        fillSalesData(sdata);
        auto dailyAverage = sdata.getDailyAverage();
        for (const auto &d: dailyAverage)
            cout << d.first << " : " << d.second << endl;
    }

    {
        cout << endl << endl << "4. feladat" << endl;
        SalesData sdata(31);
        fillSalesData(sdata);
        auto cityVisits = sdata.getCityVisits();
        for (const auto &cv: cityVisits)
        {
            cout << cv.first << " :";
            for (auto i : cv.second)
                cout << " " << i;
            cout << endl;
        }
    }

    {
        cout << endl << endl << "5. feladat" << endl;
        SalesData sdata(31);
        fillSalesData(sdata);
        auto atLeast20 = [](const DailyData &data) {
            return data.getNumberOfSales() >= 20;
        };
        sdata.listAllWhere(atLeast20);
    }

	cout << endl << endl << "Vege" << endl;
	return 0;
}
