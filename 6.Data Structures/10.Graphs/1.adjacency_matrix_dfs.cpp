/*

Time Complexity - O(V*V) // Since traversing through every node for each node.
Space Complexity - O(V)

*/

#include<bits/stdc++.h>
using namespace std;

void print_dfs(int ** edges, int v, bool * visited, int sv) {

	cout << sv << " ";
	visited[sv] = true;

	for (int i = 0; i < v; i++) {
		if (i == sv)
			continue;
		if (edges[sv][i] && !visited[i]) {
			print_dfs(edges, v, visited, i);
		}
	}
}

int main() {
	int v;
	int e;

	cin >> v >> e;

	int ** edges = new int * [v];
	for (int i = 0; i < v; i++) {
		edges[i] = new int [v];
		memset(edges[i], 0, sizeof(int)*v);
	}

	while (e--) {
		int v1, v2;
		cin >> v1 >> v2;

		edges[v1][v2] = 1;
		edges[v2][v1] = 1; // This will not be done for Directed Graphs

	}

	bool * visited = new bool[v];
	memset(visited, false, sizeof(bool)*v);

	for (int i = 0; i < v; i++) {
		if (!visited[i]) {
			print_dfs(edges, v, visited, i);
		}
	}

	for (int i = 0; i < v; i++) {
		delete [] edges[i];
	}

	delete [] edges;
	delete [] visited;

	return 0;
}
