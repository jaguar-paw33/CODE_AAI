/*

Time Complexity - O(V*V)
Space Complexity - O(V)

*/

#include<bits/stdc++.h>
using namespace std;

void print_bfs(int ** edges, int v, bool * visited, int sv) {
	queue<int> pending;
	pending.push(sv);
	visited[sv] = true;

	while (!pending.empty()) {
		int temp = pending.front();
		pending.pop();
		cout << temp << " ";
		for (int i = 0; i < v; i++) {
			if (i == temp)
				continue;
			if (edges[temp][i] && !visited[i]) {
				pending.push(i);
				visited[i] = true;
			}
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
		edges[v2][v1] = 1; // This will not be done in Directed Graph
	}

	bool * visited = new bool[v];
	memset(visited, false, sizeof(bool)*v);

	for (int i = 0; i < v; i++) {
		if (!visited[i])
			print_bfs(edges, v, visited, i);
	}

	for (int i = 0; i < v; i++) {
		delete [] edges[i];
	}

	delete [] edges;

	return 0;
}

