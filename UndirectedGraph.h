#pragma once

#include <list>

using namespace std;

class UndirectedGraph
{
public:
	UndirectedGraph(int V);
	~UndirectedGraph();
	void addEdge(int u, int v);
	int maxMatching();
private:
	int V;
	list<int>* adj;

	int lca(int* match, int* base, int* p, int a, int b);
	void markPath(int* match, int* base, bool* blossom, int* p,
		int v, int b, int children);
	int findPath(int* match, int* p, int root);
};

