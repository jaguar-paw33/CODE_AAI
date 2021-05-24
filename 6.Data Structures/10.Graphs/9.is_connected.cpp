#include<iostream>
#include<queue>
using namespace std;

void print_dfs(int ** edges, int n, int si, bool * visited) {
	visited[si] = true;
	for (int j = 0; j < n; j++) {
		if (j == si) {
			continue;
		}
		if (edges[si][j] && !visited[j]) {
			print_dfs(edges, n, j, visited);
		}
	}
}

bool DFS(int ** edges, int n) {

	bool * visited = new bool [n];

	for (int i = 0; i < n; i++) {
		visited[i] = false;
	}

	print_dfs(edges, n, 0, visited);

	bool ans = true;

	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			ans = false;
			break;
		}
	}

	delete [] visited;

	return ans;
}


int main() {
	int n, m;
	cin >> n >> m;

	if (!n)
	{
		cout << "true" << endl;
		return 0;
	}

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

	bool ans = DFS(edges, n);

	if (ans)
		cout << "true" << endl;
	else
		cout << "false" << endl;

	for (int i = 0; i < n; i++) {
		delete [] edges[i];
	}

	delete [] edges;


	return 0;
}