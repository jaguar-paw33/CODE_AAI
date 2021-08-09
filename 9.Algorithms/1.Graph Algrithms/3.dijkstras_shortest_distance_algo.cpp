
// Compute the shortest distance from a source node to a destination node with non-negtaive weights

// Time Complexity - O((n+m)logn) using prioirty queue and adjacency list
// Space Complexity - O(n)

#include<bits/stdc++.h>
using namespace std;

int findMinWeightsVertex(int * weights, bool * visited, int v) {
	int minWeightVertex = -1;
	int weight = INT_MAX;
	for (int i = 0; i < v; i++) {
		if (!visited[i] && weight > weights[i]) {
			weight = weights[i];
			minWeightVertex = i;
		}
	}
	return minWeightVertex;
}

void print_shortest_path(int ** edges, int v) {
	int weights[v];
	bool visited[v];

	for (int i = 0; i < v; i++) {
		weights[i] = INT_MAX;
		visited[i] = false;
	}

	weights[0] = 0;

	while (true) {
		int minWeightVertex = findMinWeightsVertex(weights, visited, v);
		if (minWeightVertex == -1)
			break;
		visited[minWeightVertex] = true;
		for (int i = 0; i < v; i++) {
			if (edges[minWeightVertex][i] && !visited[i] && weights[i] > (edges[minWeightVertex][i] + weights[minWeightVertex]))
			{
				weights[i] = edges[minWeightVertex][i] + weights[minWeightVertex];
			}
		}
	}

	for (int i = 0; i < v; i++) {
		cout << i << " " << weights[i] << endl;
	}
}

int main() {
	int v, e;
	cin >> v >> e;

	int ** edges = new int * [v];
	for (int i = 0; i < v; i++) {
		edges[i] = new int [v];
		for (int j = 0; j < v; j++) {
			edges[i][j] = 0;
		}
	}

	int v1, v2, w;

	while (e--) {
		cin >> v1 >> v2 >> w;
		edges[v1][v2] = w;
		edges[v2][v1] = w;
	}

	print_shortest_path(edges, v);

	for (int i = 0; i < v; i++) {
		delete [] edges[i];
	}

	delete [] edges;

	return 0;
}
2 3 5
2 4 9
3 4 4


*/
