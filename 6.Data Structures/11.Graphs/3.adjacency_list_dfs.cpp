/*

Time Complexity - O(V+E)
Space Complexity - O(V)

*/

#include<bits/stdc++.h>
using namespace std;

void print_dfs(vector<int> * edges, int v, bool * visited, int sv) {

	cout << sv << " ";
	visited[sv] = true;


	for (int i = 0; i < v; i++) {
		if (i == sv)
			continue;
		if (find(edges[sv].begin(), edges[sv].end(), i) != edges[sv].end() && !visited[i]) {
			print_dfs(edges, v, visited, i);
		}
	}
}

int main() {
	int v;
	int e;

	cin >> v >> e;

	vector<int> edges[v];

	while (e--) {
		int v1, v2;
		cin >> v1 >> v2;

		edges[v1].push_back(v2);
		edges[v2].push_back(v1); // This will not be done for Directed Graphs

	}

	bool * visited = new bool[v];
	memset(visited, false, sizeof(bool)*v);

	for (int i = 0; i < v; i++) {
		if (!visited[i]) {
			print_dfs(edges, v, visited, i);
		}
	}

	delete [] visited;

	return 0;
}
