#pragma once

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class OverlapGraph
{
public:
	OverlapGraph(vector<string> &strings);
	~OverlapGraph();
	void printStrings();
	void printMatrix();

private:
	int n;
	vector<string> strings;
	vector<vector<double>> matrix;
	bool stringBeginsWith(string &a, string &b);

	void calcOverlaps();
};

