/*

Given a graph with N vertices (numbered from 0 to N-1) and M undirected edges, then count the distinct 3-cycles in the graph. A 3-cycle PQR is a cycle in which (P,Q), (Q,R) and (R,P) are connected by an edge.

Input Format :
The first line of input contains two space separated integers, that denotes the value of N and M.
Each of the following M lines contain two integers, that denote the vertices which have an undirected edge between them. Let us denote the two vertices with the symbol u and v.

Output Format :
Print the count the number of 3-cycles in the given graph

Constraints :
0 <= N <= 100
0 <= M <= (N*(N-1))/2
0 <= u <= N - 1
0 <= v <= N - 1
Time Limit: 1 sec

Sample Input 1:
3 3
0 1
1 2
2 0
Sample Output 1:
1

*/

#include<bits/stdc++.h>
using namespace std;

int count_3_cycles(int ** edges, int n) {
	int count = 0;
	for (int i = 0; i < n - 2; i++) {
		for (int j = i + 1; j < n - 1; j++) {
			if (edges[i][j]) {
				for (int k = j + 1; k < n; k++) {
					if (edges[j][k] && edges[k][i])
						count++;
				}
			}
		}
	}
	return count;
}

int main() {
	int n, m;
	cin >> n >> m;

	int ** edges = new int * [n];
	for (int i = 0; i < n; i++) {
		edges[i] = new int [n];
		for (int j = 0; j < n; j++) {
			edges[i][j] = 0;
		}
	}

	int v1, v2;

	while (m--) {
		cin >> v1 >> v2;
		edges[v1][v2] = 1;
		edges[v2][v1] = 1;
	}
    
	if (n >= 3)
        cout << count_3_cycles(edges, n) << endl;
	else
		cout << 0 << endl;
	
	for (int i = 0; i < n; i++) {
		delete [] edges[i];
	}
	delete [] edges;
	return 0;
}



	for (int i = 0; i < v; i++) {
		delete [] edges[i];
	}

	delete [] edges;
}
