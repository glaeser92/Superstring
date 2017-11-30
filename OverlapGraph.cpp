#include "OverlapGraph.h"

OverlapGraph::OverlapGraph(vector<string> &strings)
{
	n = strings.size();

	for (auto & str : strings) {
		this->strings.push_back(str);
	}

	matrix = vector<vector<double>>(n, std::vector<double>(n));

	calcOverlaps();
}

void OverlapGraph::printMatrix() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}

void OverlapGraph::printStrings() {
	for (auto & str : strings) {
		cout << str << endl;
	}
}

void OverlapGraph::calcOverlaps() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j)
				matrix[i][j] = 0;
			else {
				//calc overlap of string i with string j
				double overlap = 0;
				int k = strings[i].length() - 1;
				int l = 0;
				while (k > 0 && l < strings[j].length()) {
					if (strings[i][k] == strings[j][l])
						overlap++;
					k--;
					l++;
				}
				matrix[i][j] = overlap;
			}
		}
	}
}


OverlapGraph::~OverlapGraph()
{
}
