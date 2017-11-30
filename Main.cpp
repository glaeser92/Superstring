#include "OverlapGraph.h"

int main() {

	vector<string> strings = { "babaa", "baaba", "aabab", "babba" };

	OverlapGraph graph(strings);
	graph.printMatrix();

	cout << endl;

	graph.printStrings();

	system("pause");
	
	return 0;
}