/*

Given an undirected graph G(V, E) and two vertices v1 and v2 (as integers), find and print the path from v1 to v2 (if exists). Print nothing if there is no path between v1 and v2.

Find the path using BFS and print the shortest path available.

Note:
1. V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
2. E is the number of edges present in graph G.
3. Print the path in reverse order. That is, print v2 first, then intermediate vertices and v1 at last.
4. Save the input graph in Adjacency Matrix.

Input Format :
The first line of input contains two integers, that denote the value of V and E.
Each of the following E lines contains two integers, that denote that there exists an edge between vertex a and b.
The following line contain two integers, that denote the value of v1 and v2.

Output Format :
Print the path from v1 to v2 in reverse order.

Constraints :
2 <= V <= 1000
1 <= E <= (V * (V - 1)) / 2
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
3 0 1

Sample Input 2 :
6 3
5 3
0 1
3 4
0 3
Sample Output 2 :

*/

#include<bits/stdc++.h>
using namespace std;

void bfs_path(int ** edges, int v, int v1, int v2) {
	bool * visited = new bool [v];
	for (int i = 0; i < v; i++) {
		visited[i] = false;
	}

	unordered_map<int, int> path; // For storing the parent child information
	queue<int> pending;

	pending.push(v1);
	visited[v1] = true;

	while (!pending.empty()) {

		int temp = pending.front();
		pending.pop();

		for (int i = 0; i < v; i++) {

			if (i == temp)
				continue;

			if (edges[temp][i] && i == v2) {
				path[v2] = temp;
				while (v2 != v1) {
					cout << v2 << " ";
					v2 = path[v2];
				}
				cout << v1 << " ";
				return;
			}

			if (edges[temp][i] && !visited[i]) {
				pending.push(i);
				visited[i] = true;
				path[i] = temp;
			}

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
		edges[v2][v1] = 1; // This will not be done for Directed Graph
	}

	cin >> v1 >> v2;

	bfs_path(edges, v, v1, v2);

	return 0;
}

