/*

An island is a small piece of land surrounded by water . A group of islands is said to be connected if we can reach from any given island to any other island in the same group . Given V islands (numbered from 1 to V) and E connections or edges between islands. Can you count the number of connected groups of islands.

Input Format :
The first line of input contains two integers, that denote the value of V and E.
Each of the following E lines contains two integers, that denote that there exists an edge between vertex a and b.

Output Format :
Print the count the number of connected groups of islands

Constraints :
0 <= V <= 1000
0 <= E <= (V * (V-1)) / 2
0 <= a <= V - 1
0 <= b <= V - 1
Time Limit: 1 second

Sample Input 1:
5 8
0 1
0 4
1 2
2 0
2 4
3 0
3 2
4 3
Sample Output 1:
1

*/

#include<bits/stdc++.h>
using namespace std;

void dfs(int ** edges, int v, int sv, bool * visited) {
	visited[sv] = true;
	for (int i = 0; i < v; i++) {
		if (i == sv)
			continue;
		if (edges[sv][i] && !visited[i]) {
			dfs(edges, v, i, visited);
		}
	}
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
		edges[v2][v1] = 1; // This will not be done for directed graph
	}

	bool * visited = new bool [v];
	for (int i = 0; i < v; i++) {
		visited[i] = false;
	}

	int count = 0;

	for (int i = 0; i < v; i++) {
		if (!visited[i]) {
			dfs(edges, v, i, visited);
			count += 1;
		}
	}

	cout << count << endl;

	return 0;
}