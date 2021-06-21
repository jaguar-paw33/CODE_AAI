/*

Time Complexity - O(V+E)
Space Complexity - O(V)

*/

#include<bits/stdc++.h>
using namespace std;

void print_bfs(vector<int> * edges, int v, bool * visited, int sv) {
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
			if (find(edges[temp].begin(), edges[temp].end(), i) != edges[temp].end() && !visited[i]) {
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

	vector<int> edges[v];

	while (e--) {
		int v1, v2;
		cin >> v1 >> v2;

		edges[v1].push_back(v2);
		edges[v2].push_back(v1); // This will not be done in Directed Graph
	}

	bool * visited = new bool[v];
	memset(visited, false, sizeof(bool)*v);

	for (int i = 0; i < v; i++) {
		if (!visited[i])
			print_bfs(edges, v, visited, i);
	}

	return 0;
}

