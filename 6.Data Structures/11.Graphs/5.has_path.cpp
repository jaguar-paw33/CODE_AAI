/*

Given an undirected graph G(V, E) and two vertices v1 and v2 (as integers), check if there exists any path between them or not. Print true if the path exists and false otherwise.

Note:
1. V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
2. E is the number of edges present in graph G.

Input Format :
The first line of input contains two integers, that denote the value of V and E.
Each of the following E lines contains two integers, that denote that there exists an edge between vertex 'a' and 'b'.
The following line contain two integers, that denote the value of v1 and v2.

Output Format :
The first and only line of output contains true, if there is a path between v1 and v2 and false otherwise.

Constraints :
0 <= V <= 1000
0 <= E <= 1000
0 <= a <= V - 1
0 <= b <= V - 1
0 <= v1 <= 2^31 - 1
0 <= v2 <= 2^31 - 1
Time Limit: 1 second

Sample Input 1 :
4 4
0 1
0 3
1 2
2 3
1 3
Sample Output 1 :
true

Sample Input 2 :
6 3
5 3
0 1
3 4
0 3
Sample Output 2 :
false

*/

/*

Time Complexity - O(V+E) and since E = O(V*V) for Adjacenecy Matrix and hence for adjacency matrix the time complexity is OV*V).
Space Complexity - O(V)

*/

#include<bits/stdc++.h>
using namespace std;

void dfs(int ** edges, int v, bool * visited, int sv) {
	visited[sv] = true;
	for (int i = 0; i < v; i++) {
		if (sv == i)
			continue;
		if (edges[sv][i] && !visited[i]) {
			dfs(edges, v, visited, i);
		}
	}
}

bool hasPath(int ** edges, int v, int v1, int v2) {
	bool * visited = new bool [v];

	for (int i = 0; i < v; i++) {
		visited[i] = false;
	}

	dfs(edges, v, visited, v1);

	bool ans = visited[v2];

	delete [] visited;

	return ans;
}

int main() {
	int v, e;
	cin >> v >> e;

	int ** edges = new int * [v];

	for (int i = 0; i < v; i++) {
		edges[i] = new int [v];
		for (int j = 0; j < v; j++) {
			edges[i][j] = 0;
		}
	}

	int v1, v2;

	while (e--) {
		cin >> v1 >> v2;
		edges[v1][v2] = 1;
		edges[v2][v1] = 1; // This will not be done for Directed Graph
	}

	cin >> v1 >> v2;

	cout << (hasPath(edges, v, v1, v2) ? "true" : "false") << endl;

	for (int i = 0; i < v; i++) {
		delete [] edges[i];
	}
	delete [] edges;

	return 0;
}
