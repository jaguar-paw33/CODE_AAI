
// Time Complexity -> Dense Graph - O(n^2)     Sparse Graph - O(n+m)
// Space Complexity -> O(n) in the worst case

// **** Gives the Shortest path between the source to other node in an Unweighted Graph*****


#include<iostream>
#include<queue>
using namespace std;

void print_bfs(int ** edges, int n, int si, bool* visited) {

	queue<int> q;
	q.push(si);

	// Vertex pushed to the Queue is marked visited so that we do not push it again
	visited[si] = true;
	while (!q.empty()) {
		int vertex = q.front();
		q.pop();
		cout << vertex << " : ";
		for (int j = 0; j < n; j++) {
			if (j == vertex)
				continue;
			if (edges[vertex][j] && !visited[j]) {
				cout << j << ",";
				q.push(j);
				visited[j] = true;
			}
		}
		cout << endl;
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

	print_bfs(edges, n, 0, visited);

	for (int i = 0; i < n; i++) {
		delete [] edges[i];
	}

	delete [] edges;
	delete [] visited;

	return 0;
}