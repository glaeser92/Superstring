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
	//while we have not arrived at the stem
	while (base[v] != b)
	{
		blossom[base[v]] = blossom[base[match[v]]] = true;
		//set predecessor
		p[v] = children;
		children = match[v];
		//consider predecessor of matching node
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

	//index of head in queue
	int qh = 0;
	//index of tail in queue
	int qt = 0;
	//queue array
	int* q = new int[V];
	//add root to queue
	q[qt++] = root;

	while (qh < qt)
	{
		//get head element of queue
		int v = q[qh++];
		for (int& to : adj[v])
		{
			//if v and to are in the same blossom or previous matching edge considered
			if (base[v] == base[to] || match[v] == to)
				continue;
			//if blossom detected
			//if we arrive at the starting node or at a matching edge from the same tree
			if (to == root || match[to] != -1 &&  p[match[to]] != -1)
			{
				//find blossom base
				int curbase = lca(match, base, p, v, to);

				bool* blossom = new bool[V];
				for (int i = 0; i < V; i++)
					blossom[i] = false;
				//mark blossom nodes
				markPath(match, base, blossom, p, v, curbase, to);
				markPath(match, base, blossom, p, to, curbase, v);

				for (int i = 0; i < V; i++)
					//if i is in blossom
					if (blossom[base[i]])
					{
						//set blossom base
						base[i] = curbase;
						//add i to queue if not used
						if (!used[i])
						{
							used[i] = true;
							q[qt++] = i;
						}
					}
			}
			//if to is not in the tree
			else if (p[to] == -1)
			{
				//add to to tree with root v
				p[to] = v;

				//if to is a free vertex
				if (match[to] == -1)
					return to;

				//add matching partner to queue
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
	//for each vertex
	for (int i = 0; i < V; i++)
		if (match[i] == -1)
		{
			//if vertex is free look for augmenting path
			int v = findPath(match, p, i);
			//augment along path
			while (v != -1)
			{
				int pv = p[v];
				int ppv = match[pv];
				match[v] = pv;
				match[pv] = v;
				v = ppv;
			}
		}
	//count number of matches
	int matches = 0;
	for (int i = 0; i < V; i++)
		if (match[i] != -1)
			matches++;
	return matches / 2;
}
