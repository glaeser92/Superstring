#include "OverlapGraph.h"
#include "BipGraph.h"
#include "Greedy.h"

int main() {

	vector<string> strings = { "babaa", "baaba", "aabab", "babba" };

	/*OverlapGraph graph(strings);
	graph.printMatrix();

	cout << endl;

	graph.printStrings();*/

	Greedy greedy(strings);

	system("pause");
	
	return 0;
}