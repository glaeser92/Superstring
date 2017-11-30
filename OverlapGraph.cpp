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
				double maxOverlap = 0;
				for (int k = strings[i].length() - 1; k >= 0; k--)
				{
					if (stringBeginsWith(strings[i].substr(k), strings[j]))
					{
						if ((strings[i].length() - k) > maxOverlap) {
							maxOverlap = strings[i].length() - k;
						}
					}
				}
				matrix[i][j] = maxOverlap;
			}
		}
	}
}

bool OverlapGraph::stringBeginsWith(string &a, string &b) {
	if (a.length() > b.length()) {
		return false;
	}
	for (int i = 0; i < a.length(); i++) {
		if (a[i] != b[i]) {
			return false;
		}
	}
	return true;
}


OverlapGraph::~OverlapGraph()
{
}
