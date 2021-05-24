#include<iostream>
using namespace std;

void dfs(int ** edges, int n, int si, bool * visited) {
	visited[si] = true;
	for (int j = 0; j < n; j++) {
		if (j == si) {
			continue;
		}
		if (edges[si][j] && !visited[j]) {
			dfs(edges, n, j, visited);
		}
	}
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
		int u, v;
		cin >> u >> v;
		edges[u][v] = 1;
		edges[v][u] = 1;
	}

	bool * visited = new bool[n];

	for (int i = 0; i < n; i++) {
		visited[i] = false;
	}

	int u1, u2;
	cin >> u1 >> u2;

	dfs(edges, n, u1, visited);

	if (visited[u2]) {
		cout << "true" << endl;
	} else {
		cout << "false" << endl;
	}

	for ( int i = 0; i < n; i++) {
		delete [] edges[i];
	}

	delete [] visited;
	delete [] edges;

	return 0;
}