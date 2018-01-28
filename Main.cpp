#include "OverlapGraph.h"
#include "BipGraph.h"
#include "Greedy.h"
#include "UndirectedGraph.h"

int main() {

	vector<string> strings = { "babaa", "baaba", "aabab", "babba" };

	UndirectedGraph g(6);
	g.addEdge(0, 1);
	g.addEdge(1, 2);
	g.addEdge(1, 3);
	g.addEdge(3, 4);
	g.addEdge(4, 5);
	g.addEdge(5, 3);
	g.addEdge(5, 2);

	cout << g.maxMatching() << endl;

	system("pause");
	
	return 0;
}