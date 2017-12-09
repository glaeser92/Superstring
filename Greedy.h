#pragma once

#include <string>
#include <iostream>
#include <vector>

using namespace std;

typedef struct Edge
{
	int src, dest, weight;
} Edge;

class Greedy
{
public:
	Greedy(vector<string> &strings);
	void printEdges();
	~Greedy();

private:
	int n;
	vector<Edge> edges;
	vector<string> strings;

	void calcOverlaps();
	void calcSuperstring();
	bool stringBeginsWith(string &a, string &b);
};

