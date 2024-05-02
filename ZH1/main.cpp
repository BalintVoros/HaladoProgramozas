#include <iostream>
#include <utility>
#include <fstream>
#include <cmath>
#include "statcollector.h"

namespace Statistics {}

using namespace std;
using namespace Statistics;

vector<double> generateVector(double start, unsigned seed, unsigned size);
list<double> generateList(double start, unsigned seed, unsigned size);
void generateArray(double *array, double start, unsigned seed, unsigned size);
void generateFile(const string &filename, double start, unsigned seed, unsigned size);


// Ide kerül a sablonos függvény
template <class T>
void sortArray(T *array, unsigned size)
{
	for (unsigned i=0; i<size-1; i++)
	{
		unsigned min_idx=i;
		for (unsigned k=i+1; k<size; k++)
			if (array[k]<array[min_idx])
				min_idx=k;
		if (min_idx!=i)
		{
			T temp=array[i];
			array[i]=array[min_idx];
			array[min_idx]=temp;
		}
	}
}

int main()
{

	// bemeneti teszt adatok
	vector<double> v[4]={generateVector(321.542, 1974, 10),generateVector(225.325, 6547, 30),generateVector(234.121, 8124, 50),vector<double>()};
	list<double> l[4]={generateList(128.431, 2166, 10),generateList(654.451, 1256, 30),list<double>(),generateList(764.242, 6514, 50)};
	double *t[4]={new double[10], nullptr, new double[30], new double[50]};
	unsigned sizes[4]={10,0,30,50};
	generateArray(t[0], 321.611, 4633, 10);
	generateArray(t[2], 643.764, 1272, 30);
	generateArray(t[3], 976.211, 8765, 50);
	string filenames[4]={"input1.txt", "input2.txt", "input3.txt", "input4.txt"};
	generateFile(filenames[1], 654.299, 5643, 10);
	generateFile(filenames[2], 875.221, 6547, 30);
	generateFile(filenames[3], 128.254, 9186, 50);

	{
		cout << endl << endl << "nevter teszt" << endl;
		Statistics::StatCollector sc(v[0]);
		sc.printStats();
	}

	{
		cout << endl << endl << "exception teszt" << endl;
		list<pair<unsigned,unsigned>> inputSelector={{1,1},{1,3},{3,3},{2,1},{1,4},{4,2},{3,1},{3,4},{4,1},{4,4},{3,2},{4,3},{1,2},{2,2},{2,3},{2,4}};
		// Ennek a ciklusnak az egyes iterációit kell védeni kivétel kezeléssel
		for (auto p : inputSelector)
		{
			try{
				StatCollector *sc;
				if (p.first==1) sc=new StatCollector(v[p.second-1]);
				else if (p.first==2) sc=new StatCollector(l[p.second-1]);
				else if (p.first==3) sc=new StatCollector(t[p.second-1], sizes[p.second-1]);
				else sc=new StatCollector(filenames[p.second-1]);
				sc->printStats();
				delete sc;
			}
			catch (exception &e)
			{
				cout << e.what() << endl;
			}
		}
	}

	{
		cout << endl << endl << "sablon teszt" << endl;
		int arrayInt[20]={54,12,5,5,-1,54,1,65,-56,-53,-654,234,654,-773,13,65,1,89,834,6};
		double arrayDouble[14]={-321.43,632.53,12.5,65.2,766.14,-3333.555,-2.4,211.543,-66.2218,68.87,555.842,44,745,122.8};
		string arrayString[10]={"something","nothing","other","lol","apple","water","earth","fire","air","final"};
		sortArray(arrayInt,20);
		sortArray(arrayDouble,14);
		sortArray(arrayString,10);
		for (int i : arrayInt) cout << i << " ";
		cout << endl;
		for (double d : arrayDouble) cout << d << " ";
		cout << endl;
		for (string s : arrayString) cout << s << " ";
		cout << endl;
	}

	for (unsigned i=0; i<3; i++)
		delete t[i];

	cout << endl << endl << "Vege" << endl << endl;

	return 0;
}

vector<double> generateVector(double start, unsigned seed, unsigned int size)
{
	vector<double> result(size);
	result[0]=start;
	for (unsigned i=1; i<size; i++)
	{
		result[i] = (int(floor(result[i-1]*316521))%seed+125.568)/10.25;
	}
	return result;
}

list<double> generateList(double start, unsigned seed, unsigned size)
{
	vector<double> vec=generateVector(start, seed, size);
	return list<double>(vec.begin(), vec.end());
}

void generateArray(double *array, double start, unsigned seed, unsigned size)
{
	vector<double> vec=generateVector(start, seed, size);
	for (unsigned i=0; i<size; i++)
		array[i]=vec[i];
}

void generateFile(const string &filename, double start, unsigned seed, unsigned size)
{
	vector<double> vec=generateVector(start, seed, size);
	ofstream output(filename);
	for (double d : vec)
		output << d << " ";
	output << endl;
}
