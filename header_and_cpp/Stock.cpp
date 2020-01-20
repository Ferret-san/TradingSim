#include "Stock.h"
#include <fstream>
#include <sstream>
#include <vector>
using std::ifstream;
using std::stringstream;
using std::vector;
Stock::Stock()
{
	this->name = "N/A";
}
Stock::Stock(string csvFile)
{
	
	string path = "SP500_StockData/";
	path += csvFile;
	path += "_data.csv";
	ifstream file(path);
	string line, parameter;
	vector<string> row;
	int i = 0;

	while (getline(file, line))
	{
		if (i == 0)
		{
			i++;
			continue;
		}
		row.clear();
		stringstream lineData(line);

		while (getline(lineData, parameter, ','))
		{
			row.push_back(parameter);
		}

		this->open.push_back(stod(row[1]));
		this->high.push_back(stod(row[2]));
		this->low.push_back(stod(row[3]));
		this->close.push_back(stod(row[4]));
		this->volume.push_back(stoi(row[5]));

	}
	file.close();
}
