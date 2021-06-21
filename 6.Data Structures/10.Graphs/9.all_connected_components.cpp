/*

Given an undirected graph G(V,E), find and print all the connected components of the given graph G.

Note:
1. V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
2. E is the number of edges present in graph G.
3. You need to take input in main and create a function which should return all the connected components. And then print them in the main, not inside function.
Print different components in new line. And each component should be printed in increasing order (separated by space). Order of different components doesn't matter.

Input Format :
The first line of input contains two integers, that denote the value of V and E.
Each of the following E lines contains two space separated integers, that denote that there exists an edge between vertex a and b.

Output Format :
Print different components in new line. And each component should be printed in increasing order of vertices (separated by space). Order of different components doesn't matter.

Constraints :
0 <= V <= 1000
0 <= E <= (V * (V - 1)) / 2
0 <= a <= V - 1
0 <= b <= V - 1

Sample Input 1:
4 2
0 1
2 3
Sample Output 1:
0 1
2 3

Sample Input 2:
4 3
0 1
1 3
0 3
Sample Output 2:
0 1 3
2
*/

#include<bits/stdc++.h>
using namespace std;

void dfs(int ** edges, int v, int sv, bool * visited, vector<int> & compo) {
	visited[sv] = true;
	compo.push_back(sv);
	for (int i = 0; i < v; i++) {
		if (i == sv)
			continue;
		if (edges[sv][i] && !visited[i]) {
			dfs(edges, v, i, visited, compo);
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

	vector<int> compo;

	for (int i = 0; i < v; i++) {
		if (!visited[i]) {
			dfs(edges, v, i, visited, compo);
			sort(compo.begin(), compo.end());
			for (int i = 0; i < compo.size(); i++) {
				cout << compo[i] << " ";
			}
			cout << endl;
			compo.erase(compo.begin(), compo.end());
		}
	}
	return 0;
}