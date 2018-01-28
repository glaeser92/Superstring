#include "OverlapGraph.h"
#include "BipGraph.h"
#include "Greedy.h"
#include "UndirectedGraph.h"

int main() {

	vector<string> strings = { "babaa", "baaba", "aabab", "babba" };

	UndirectedGraph g(7);
	g.addEdge(3, 6);
	g.addEdge(3, 1);
	g.addEdge(1, 4);
	g.addEdge(4, 5);
	g.addEdge(5, 2);
	g.addEdge(2, 0);
	g.addEdge(1, 0);

	cout << g.maxMatching() << endl;

	system("pause");
	
	return 0;
}