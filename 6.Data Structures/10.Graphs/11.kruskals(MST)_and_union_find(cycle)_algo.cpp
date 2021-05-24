
// Spanning Tree - A tree which contains all the vertices of a connected and undirected Graph.

// In Spanning Tree |V| = n and |E = n-1

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

				Intiution - Add an edge between two vertices only if they belong to difference components i.e. having different top most parent.

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

	Since,we need to choose edges based on the minimum weight value and hence we will not use	adjacency matrix to store the input instead we will crease an edge class and will use the array of edge class.
*/

/*
	Time Complexity for Kruskal's Algo -

		Sorting Input Array - mlog(m)
		Performing Cycle Detection - mn in worst case

		Hence, Time Complexity for Kruskal's Algo = O(mlogm+mn)

		This is not very good if we have m of order O(n^2), to avoid this we use union by rank to perform cycle detection which take O(mlogn) time and hence
		we get the final time coplexity of O(mlogm + mlogn)
*/

#include<bits/stdc++.h>
using namespace std;

class edge {

public:
	int s;
	int d;
	int w;
};

bool comp(edge e1, edge e2) {
	return e1.w < e2.w;
}

// Finding the topmost parent
int find_parent(int vertex, int * parent) {

	while (vertex != parent[vertex])
		vertex = parent[vertex];

	return vertex;
}

void Kruskals(edge * input, int n, int m) {

	sort(input, input + m, comp); // Sorting the Edge Array in ascending order of weights

	edge * output = new edge[n - 1]; // Output MST will have n-1 edges

	int count = 0; //To store the number of edges added to the MST

	int * parent = new int [n]; // To store the initial parent of each vertex (Union Find Algo)

	for (int i = 0; i < n; i++) {
		parent[i] = i;
	}

	int i = 0 ;

	// Stop when added n-1 vertices in the output
	while (count < n - 1) {

		edge e = input[i++];
		int s = e.s;
		int d = e.d;
		int ps = find_parent(s, parent);
		int pd = find_parent(d, parent);

		if (ps != pd) {
			output[count++] = e;

			// Updating the top most parents (ps or pd) and not the current source (s) or destination(d)
			parent[pd] = ps; // Update the topmost parent of either source or destination since both have
			//  become part of a single component and hence the parent of source will become the parent of destination or vice versa.
		}

	}

	for (int i = 0; i < n - 1; i++) {
		cout << min(output[i].s, output[i].d) << " " << max(output[i].s, output[i].d) << " " << output[i].w << endl;
	}

}

int main() {

	int n, m;
	cin >> n >> m;

	edge * input = new edge[m]; // Input will have m edges


	// Taking Input
	for (int i = 0; i < m; i++) {
		int s, d, w;
		cin >> s >> d >> w;
		input[i].s = s;
		input[i].d = d;
		input[i].w = w;
	}

	Kruskals(input, n, m);

	return 0;
}
