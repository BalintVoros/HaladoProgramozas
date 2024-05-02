#include "statcollector.h"
#include <iostream>
#include <fstream>

namespace Statistics {

void StatCollector::calculate()
{
	if (values.size()==0) throw EmptyDataSetException();
	minValue=maxValue=values[0];
	double sum=values[0];
	for (unsigned i=1; i<values.size(); i++)
	{
		sum+=values[i];
		if (values[i]<minValue) minValue=values[i];
		if (values[i]>maxValue) maxValue=values[i];
	}
	average=sum/values.size();
}

StatCollector::StatCollector(const vector<double> &_values):
	values(_values)
{
	calculate();
}

StatCollector::StatCollector(const list<double> &_values):
	values(_values.begin(), _values.end())
{
	calculate();
}

StatCollector::StatCollector(const double *_values, unsigned int count):
	values(count)
{
	for (unsigned i=0; i<count; i++)
		values[i]=_values[i];
	calculate();
}

StatCollector::StatCollector(const string &fileName)
{
	ifstream input(fileName);
	if (!input.is_open()) throw FileNotFoundException(fileName);
	double value;
	input >> value;
	while (!input.eof())
	{
		values.push_back(value);
		input >> value;
	}
	calculate();
}

void StatCollector::printStats() const
{
	cout << "Number of values: " << values.size() << ",    ";
	cout << "min: " << minValue << ", max: " << maxValue << ", average: " << average << endl;
}

StatCollector::FileNotFoundException::FileNotFoundException(const string &filename):
	msg("Unable to load data: file " + filename + " not found")
{
}

const char *StatCollector::FileNotFoundException::what() const noexcept
{
	return msg.c_str();
}

const char *StatCollector::EmptyDataSetException::what() const noexcept
{
	return "Unable to calculate statistics: data set is empty";
}

} // namespace Statistics
