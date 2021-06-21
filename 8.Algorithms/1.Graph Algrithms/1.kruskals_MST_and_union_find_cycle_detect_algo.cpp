
// Spanning Tree - A tree which contains all the vertices of a connected and undirected Graph.

// In Spanning Tree |V| = n and |E| = n-1

// Minimum Spanning Tree - A spanning tree with least(having the minimum sum of weights) weight formed from a weighted, undirected and connected Graph.

/*
Kruskal's Algorithm (Greedily Pick Edges with least weight) -

   1. Pick an edge one by one until we have n-1 edges (and automatically n vertices).
   2. The edge is picked such that it has the least weight among the non-picked edges
   	  and it does not produce a cycle when added to the MST.

		Cycle Detection - To add an edge between u and v,

			1. If a path exists between u and v, then we can't add an edge between u and v
			   since it will introduce cycle.

			2. If a path does not exists, then we can add an edge.

			To Check the path between u and v using BFS or DFS, the time complexity is O(n+m) which is not very good for our usecase.

			To overcome this issue we use Union Find Algorithm to detect cycle,

				Intiution - Add an edge between two vertices only if they belong to different components i.e. having different top most parent.

				Algo ->

					1. Consider each verted to be disjoint i.e. no edge between any vertex and all vertices have themselves as their parent.
					2. To draw an edge between u and v, find the parent of u and v,
						- if both the parents are different then add an edge.
						- else adding an edge will result in a cycle.
					3. After adding an edge between u and v if they had different parents, change the parents of u and v, make u as the parent of v or vice-versa.
					4. Now, keep on repeating the above steps until we get the required results.

				Time Complexity of Union-Find Algo is O(n) which is much better than O(n+m).
*/

/*
Input Format - n,m
			   for each m
			     source, dest and weight

	Since,we need to choose edges based on the minimum weight value and hence we will not use adjacency matrix to store the input instead we will create an edge class and will use the array of edge class.
*/

/*
	Time Complexity for Kruskal's Algo -

		Sorting Input Array wrt weights - mlog(m)
		Performing Cycle Detection - mn in worst case

		Hence, Time Complexity for Kruskal's Algo = O(mlogm+mn)

		This is not very good if we have m of order O(n^2), to avoid this we use union by rank to perform cycle detection which take O(mlogn) time and hence
		we get the final time complexity of O(mlogm + mlogn)
*/



#include<bits/stdc++.h>
using namespace std;

class weighted_edge {
public:
	int v1;
	int v2;
	int w;
};

bool comparator(weighted_edge e1, weighted_edge e2) {
	return e1.w < e2.w;
}

int find_parent(int * parent, int v) {
	while (v != parent[v]) {
		v = parent[v];
	}
	return v;
}

void print_mst(weighted_edge * graph, int v, int e) {
	sort(graph, graph + e, comparator);

	int parent[v];
	for (int i = 0; i < v; i++) {
		parent[i] = i;
	}

	weighted_edge mst[v - 1];

	for (int i = 0, j = 0; i < e; i++) {
		weighted_edge e = graph[i];
		int p1 = find_parent(parent, e.v1);
		int p2 = find_parent(parent, e.v2);
		if (p1 != p2) {
			mst[j++] = e;
			parent[p2] = parent[p1];
		}
	}

	for (int i = 0; i < v - 1; i++) {
		weighted_edge e = mst[i];
		cout << min(e.v1, e.v2) << " " << max(e.v1, e.v2) << " " << e.w << endl;
	}
}

int main() {
	int v, e;
	cin >> v >> e;

	weighted_edge * graph = new weighted_edge[e];

	int v1, v2, w;

	for (int i = 0; i < e; i++) {
		cin >> v1 >> v2 >> w;
		weighted_edge e;
		e.v1 = v1;
		e.v2 = v2;
		e.w = w;
		graph[i] = e;
	}

	print_mst(graph, v, e);

	delete [] graph;

	return 0;
}
