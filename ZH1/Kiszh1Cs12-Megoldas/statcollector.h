#ifndef STATCOLLECTOR_H
#define STATCOLLECTOR_H

#include <vector>
#include <string>
#include <list>
#include <exception>

using namespace std;

namespace Statistics {

class StatCollector
{
	vector<double> values;
	double minValue, maxValue, average;

	void calculate();
public:
	StatCollector(const vector<double> &_values);
	StatCollector(const list<double> &_values);
	StatCollector(const double *_values, unsigned int count);
	StatCollector(const string &fileName);
	void printStats() const;

	class FileNotFoundException : public exception
	{
		string msg;
	public:
		FileNotFoundException(const string &filename);
		const char *what() const noexcept;
	};

	class EmptyDataSetException : public exception
	{
	public:
		const char *what() const noexcept;
	};
};

} // namespace Statistics

#endif // STATCOLLECTOR_H
