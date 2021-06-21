
// Greedily pick vertex which has least weight.

// Time Complexity - O((m+n)logn) after using min priority queue and adjacency list
// Space Complexity - O(n)

#include<iostream>
#include<climits>
using namespace std;


int findMinVertex(int * weights, bool * visited, int n) {

// To find minimum weight vertex we should use min pririty queue with some modfications

	int minVertex = -1;
	int minVertexWeight = INT_MAX;

	for (int i = 0; i < n; i++) {
		if (!visited[i] && minVertexWeight > weights[i]) {
			minVertex = i;
		}
	}
	
	return minVertex;
}


void prims(int ** edges, int n) {

	int * parents = new int  [n];
	bool * visited = new bool [n];
	int * weights = new int [n];

	for (int i = 0; i < n; i++) {
		parents[i] = -1;
		visited[i] = false;
		weights[i] = INT_MAX;
	}

	weights[0] = 0;

	while(true) {

		int minVertex = findMinVertex(weights, visited, n);
		if(minVertex==-1)
			break;
			
		visited[minVertex] = true;

		for (int j = 0; j < n; j++) {
			if (edges[minVertex][j] && !visited[j]) {
				if (edges[minVertex][j] < weights[j]) {
					weights[j] = edges[minVertex][j];
					parents[j] = minVertex;
				}
			}
		}
	}

	for (int i = 1; i < n; i++) {
		cout << min(parents[i], i) << " " << max(parents[i], i) << " " << weights[i] << endl;
	}
	
	delete [] visited;
	delete [] parents;
	delete [] weights;
}


int main() {

	int n, m;
	cin >> n >> m;

	if (!n)
		return 0;

	int ** edges = new int * [n]; // We should use Adjacency List instead of Adjacency Matrix

	for (int i = 0; i < n; i++) {
		edges[i] = new int [n];
		for (int j = 0; j < n; j++) {
			edges[i][j] = 0;
		}
	}

	for (int i = 0; i < m; i++) {
		int s, d, w;
		cin >> s >> d >> w;
		edges[s][d] = w;
		edges[d][s] = w;
	}

	cout << endl;

	prims(edges, n);

	for (int i = 0; i < n; i++) {
		delete [] edges[i];
	}

	delete [] edges;

	return 0;
}
