#include<iostream>
#include<queue>
using namespace std;

void print_dfs(int ** edges, int n, int si, bool * visited) {
	cout << si << " ";
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

void print_bfs(int ** edges, int n, int si, bool * visited) {
	queue<int> q;
	q.push(si);
	visited[si] = true;
	while (!q.empty()) {
		int vertex = q.front();
		q.pop();
		cout << vertex << " ";
		for (int j = 0; j < n; j++) {
			if (j == vertex) {
				continue;
			}
			if (edges[vertex][j] && !visited[j]) {
				q.push(j);
				visited[j] = true;
			}
		}
	}
}

void DFS(int ** edges, int n) {

	bool * visited = new bool [n];

	for (int i = 0; i < n; i++) {
		visited[i] = false;
	}

	cout << "DFS:" << endl;

	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			print_dfs(edges, n, i, visited);
		}
	}

	delete [] visited;
}

void BFS(int ** edges, int n) {

	bool * visited = new bool [n];

	for (int i = 0; i < n; i++) {
		visited[i] = false;
	}
	cout << endl << "BFS:" << endl;

	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			print_bfs(edges, n, i, visited);
		}
	}

	delete [] visited;
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

	DFS(edges, n);

	BFS(edges, n);

	for (int i = 0; i < n; i++) {
		delete [] edges[i];
	}

	delete [] edges;


	return 0;
}