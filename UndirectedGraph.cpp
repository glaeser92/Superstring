#include "stdafx.h"
#include "UndirectedGraph.h"


UndirectedGraph::UndirectedGraph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}

UndirectedGraph::~UndirectedGraph()
{
}

void UndirectedGraph::addEdge(int u, int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}

int UndirectedGraph::lca(int* match, int* base, int* p, int a, int b)
{
	bool* used = new bool[V];
	for (int i = 0; i < V; i++)
	{
		used[i] = false;
	}
	while (true)
	{
		a = base[a];
		used[a] = true;
		if (match[a] == -1)
			break;
		a = p[match[a]];
	}
	while (true)
	{
		b = base[b];
		if (used[b])
			return b;
		b = p[match[b]];
	}
}

void UndirectedGraph::markPath(int* match, int* base, bool* blossom, int* p, int v, int b, int children)
{
	while (base[v] != b)
	{
		blossom[base[v]] = blossom[base[match[v]]] = true;
		p[v] = children;
		children = match[v];

		v = p[match[v]];
	}
}

int UndirectedGraph::findPath(int* match, int* p, int root)
{
	bool* used = new bool[V];
	int* base = new int[V];
	for (int i = 0; i < V; i++)
	{
		p[i] = -1;
		used[i] = false;
		base[i] = i;
	}
	used[root] = true;

	int qh = 0;
	int qt = 0;
	int* q = new int[V];
	q[qt++] = root;

	while (qh < qt)
	{
		int v = q[qh++];
		for (int& to : adj[v])
		{
			if (base[v] == base[to] || match[v] == to)
				continue;
			if (to == root || match[to] != -1 &&  p[match[to]] != -1)
			{
				int curbase = lca(match, base, p, v, to);
				bool* blossom = new bool[V];
				markPath(match, base, blossom, p, v, curbase, to);
				markPath(match, base, blossom, p, to, curbase, v);
				for (int i = 0; i < V; i++)
					if (blossom[base[i]])
					{
						base[i] = curbase;
						if (!used[i])
						{
							used[i] = true;
							q[qt++] = i;
						}
					}
			}
			else if (p[to] == -1)
			{
				p[to] = v;
				if (match[to] == -1)
					return to;
				to = match[to];
				used[to] = true;
				q[qt++] = to;
			}
		}
	}
	return -1;
}

int UndirectedGraph::maxMatching()
{
	int* match = new int[V];
	for (int i = 0; i < V; i++)
		match[i] = -1;
	int* p = new int[V];
	for (int i = 0; i < V; i++)
		if (match[i] == -1)
		{
			int v = findPath(match, p, i);
			while (v != -1)
			{
				int pv = p[v];
				int ppv = match[pv];
				match[v] = pv;
				match[pv] = v;
				v = ppv;
			}
		}
	int matches = 0;
	for (int i = 0; i < V; i++)
		if (match[i] != -1)
			matches++;
	return matches / 2;
}
