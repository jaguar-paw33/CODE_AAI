
// We will be printing path from destination to sorce node.


#include<iostream>
using namespace std;

void get_path_dfs(int ** edges, int n, int s, int d, bool* visited, int * pred) {

	if (s == d) {
		return;
	}

	if (pred[s] == -1)
		pred[s] = s;
	visited[s] = true;

	for (int j = 0; j < n; j++) {
		if (j == s)
			continue;
		if (edges[s][j] && !visited[j]) {
			if (pred[j] == -1)
				pred[j] = s;
			get_path_dfs(edges, n, j, d, visited, pred);
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

	bool * visited = new bool [n];
	for (int i = 0; i < n; i++) {
		visited[i] = false;
	}

	int * pred = new int [n];

	for (int i = 0; i < n; i++) {
		pred[i] = -1;
	}

	int s, d;
	cin >> s >> d;

	if (s < 0 || s >= n || d < 0 || d >= n)
		return 0;

	get_path_dfs(edges, n, s, d, visited, pred);

	if (pred[d] != -1) {
		while (d != s) {
			cout << d << " ";
			d = pred[d];
		}
		cout << s << endl;
	}

	for ( int i = 0; i < n; i++) {
		delete [] edges[i];
	}

	delete [] visited;
	delete [] edges;

	return 0;

}