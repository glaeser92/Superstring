#include "Greedy.h"

Greedy::Greedy(vector<string> &strings)
{
	n = strings.size();

	for (auto & str : strings) {
		this->strings.push_back(str);
	}
	calcSuperstring();
}

void Greedy::calcOverlaps() {
	n = strings.size();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i != j)
			{
				//calc overlap of string i with string j
				int maxOverlap = 0;
				for (int k = strings[i].length() - 1; k >= 0; k--)
				{
					string str = strings[i].substr(k);
					if (stringBeginsWith(str, strings[j]))
					{
						if ((strings[i].length() - k) > maxOverlap) {
							maxOverlap = strings[i].length() - k;
						}
					}
				}
				edges.push_back(Edge{ i, j, maxOverlap });
			}
		}
	}
}

void Greedy::calcSuperstring() {

	while (strings.size() > 1) {
		calcOverlaps();

		//print edges
		printEdges();
		cout << endl;

		// merge strings
		int maxWeight = 0;
		int maxIndex = 0;
		for (int i = 0; i < edges.size(); i++) {
			if (edges[i].weight > maxWeight) {
				maxWeight = edges[i].weight;
				maxIndex = i;
			}
		}
		string sourceString = strings[edges[maxIndex].src];
		string destString = strings[edges[maxIndex].dest];
		int overlap = edges[maxIndex].weight;

		string newString = sourceString.substr(0, sourceString.length() - overlap) +
			sourceString.substr(sourceString.length() - overlap, overlap) +
			destString.substr(overlap, destString.length() - overlap);

		for (auto it = strings.begin(); it != strings.end(); ) {
			if ((*it).compare(sourceString) == 0 || (*it).compare(destString) == 0) {
				it = strings.erase(it);
			}
			else {
				++it;
			}
		}

		strings.push_back(newString);
		edges.clear();

		//print strings
		for (auto & str : strings) {
			cout << str << " ";
		}
		cout << endl;
		cout << endl;
	}

	cout << strings[0] << endl;
}

bool Greedy::stringBeginsWith(string &a, string &b) {
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

void Greedy::printEdges() {
	for (auto & edge : edges) {
		cout << edge.src << " - " << edge.dest << " : " << edge.weight << endl;
	}
}


Greedy::~Greedy()
{
}
