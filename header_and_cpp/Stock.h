#pragma once
#include <vector>
#include <string>
using std::string;
using std::vector;
struct Stock
{
	string name;
	vector<double> open; //open price is stored hisotrically, from oldest to the most recent
	vector<double> close; //stored the same as open
	vector<double> low; //stored the same as open
	vector<double> high; //stored the same as open
	vector<int> volume; //stored the same as prices
	Stock();
	Stock(string csvFile);

};

