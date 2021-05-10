
// Compute the shortest distance from a source node to a destination node

// Time Complexity - O((n+m)logn) using prioirty queue and adjacency list
// Space Complexity - O(n)

#include<iostream>
#include<climits>
using namespace std;

int findMinVertex(int * weights, bool * visited, int n) {
	int minVertex = -1;
	for (int i = 0; i < n; i++) {
		if (!visited[i] && (minVertex == -1 || weights[i] < weights[minVertex])) {
			minVertex = i;
		}
	}
	return minVertex;
}


void dijkstras(int ** edges, int n) {

	bool * visited = new bool[n];
	int * weights = new int[n];

	for (int i = 0; i < n; i++) {
		visited[i] = false;
		weights[i] = INT_MAX;
	}

	weights[0] = 0;

	for (int i = 0; i < n; i++) {
		int minVertex = findMinVertex(weights, visited, n);
		visited[minVertex] = true;

		for (int j = 0; j < n; j++) {
			if (edges[minVertex][j] && !visited[j]) {
				int d = weights[minVertex] + edges[minVertex][j];
				if (weights[j] > d) {
					weights[j] = d;
				}
			}
		}
	}

	for (int i = 0; i < n; i++) {
		cout << i << " " << weights[i] << endl;
	}

	delete [] visited;

	return;

}


int main() {

	int n, m;
	cin >> n >> m;

	if (!n)
		return 0;

	int ** edges = new int * [n];

	for (int i = 0; i < n; i++) {
		edges[i] = new int [n];
		for (int j = 0; j < n; j++) {
			edges[i][j] = 0;
		}
	}

	for (int i = 0; i < m; i++) {
		int s, d, w;
		cin >> s >> d >> w;

		// Considering the Graph to be undirected

		edges[s][d] = w;
		edges[d][s] = w;
	}

	cout << endl;

	dijkstras(edges, n);

	for (int i = 0; i < n; i++) {
		delete [] edges[i];
	}

	delete [] edges;
	return 0;

}


/*



5 7
0 1 4
0 2 8
1 3 5
1 2 2
2 3 5
2 4 9
3 4 4


*/