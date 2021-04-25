
// Time Complexity -> O(n+m)
// Space Complexity -> O(n)


#include<iostream>
using namespace std;


void print_dfs(int ** edges, int n, int si, bool * visited) {
	cout << si << " "; // Printing only one edge and then calling on the connected edges to this edge
	visited[si] = true;
	for (int j = 0; j < n; j++) {
		if (j == si)
			continue;
		if (edges[si][j] && !visited[j]) {
			print_dfs(edges, n, j, visited);
		}
	}
	return;
}


int main() {

	int n;
	cin >> n;

	if (!n)
		return 0;

	int m;
	cin >> m;

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

	bool * visited = new bool [n];
	for (int i = 0; i < n; i++) {
		visited[i] = false;
	}

	cout << endl << "DFS : ";
	print_dfs(edges, n, 0, visited);

	for (int i = 0; i < n; i++) {
		delete [] edges[i];
	}

	delete [] edges;
	delete [] visited;

	return 0;
}