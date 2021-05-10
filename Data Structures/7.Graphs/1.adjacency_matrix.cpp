#include<iostream>
using namespace std;


// The print format here is DFS
void print_graph(int ** edges, int n, int si, bool * visited) {
	cout << si << " ";
	visited[si] = true;
	for (int j = 0; j < n; j++) {
		if (j == si)
			continue;
		if (edges[si][j] && !visited[j]) {
			print_graph(edges, n, j, visited);
		}
	}
	return;
}


int main() {

	// Input the Number of Vertices
	int n;
	cin >> n;

	if (!n)
		return 0;

	// Input the number of edges
	int m;
	cin >> m;

	// Assuming the Vertex to be from 0 to n-1.

	// Initializing the Adjacency Matrix
	int ** edges = new int * [n];
	for (int i = 0; i < n; i++) {
		edges[i] = new int [n];
		for (int j = 0; j < n; j++) {
			edges[i][j] = 0;
		}
	}


	// Taking edges as Input and marking in the Adjacency Matrix
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		edges[u][v] = 1;
		edges[v][u] = 1; // This will not be done if we have a directed graph u -> v.
	}

	// Creating a Visited Matrix which keeps track of the visited vertices while Printing
	bool * visited = new bool [n];
	for (int i = 0; i < n; i++) {
		visited[i] = false;
	}

	// Printing the Graph in the Depth First Format starting from 0
	// Also passing the vertex from which we need to start printing the graph
	// Taking 0 as the Initial Vertex to print
	print_graph(edges, n, 0, visited);

	for (int i = 0; i < n; i++) {
		delete [] edges[i];
	}

	delete [] edges;
	delete [] visited;
	return 0;
}