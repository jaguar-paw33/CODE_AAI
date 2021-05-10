#include<bits/stdc++.h>
using namespace std;

void print_dfs(int ** edges, int n, int si, bool * visited, vector<int>& comp) {
	comp.push_back(si);
	visited[si] = true;
	for (int j = 0; j < n; j++) {
		if (j == si) {
			continue;
		}
		if (edges[si][j] && !visited[j]) {
			print_dfs(edges, n, j, visited, comp);
		}
	}
}

void DFS(int ** edges, int n) {

	bool * visited = new bool [n];
	vector<int> comp;

	for (int i = 0; i < n; i++) {
		visited[i] = false;
	}

	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			comp.erase(comp.begin(), comp.end());
			print_dfs(edges, n, i, visited, comp);
			sort(comp.begin(), comp.end());
			for (int i = 0; i < comp.size(); i++) {
				cout << comp[i] << " ";
			}
			cout << endl;
		}
	}

	delete [] visited;
}


int main() {
	int n, m;
	cin >> n >> m;

	if (!n)
	{
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

	DFS(edges, n);

	for (int i = 0; i < n; i++) {
		delete [] edges[i];
	}

	delete [] edges;


	return 0;
}