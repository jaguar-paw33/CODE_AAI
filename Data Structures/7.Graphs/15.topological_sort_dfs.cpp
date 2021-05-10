/*

Topological Sort (for directed acyclic graph)-

	Suppose we have multiple tasks and each task is dependent on some other tasks i.e.
	we can only start a particular task when we have completed the other tasks which
	this task depends on. Now, this whole structure of tasks can be represented using a
	directed graph in which a vertex from node u to v denotes that the task u must be completed
	before starting the task v.

	Now, the ordering of all the tasks where each task is only started after completing its
	dependent tasks is called as Topological Sorted Ordering and to perform topological sorting
	we can use DFS.

	Time Complexity - O(n+m)
	Space Complexity - O(n)

*/

#include<iostream>
#include<stack>
using namespace std;


void dfs(int ** edges, int n, int si, bool * visited, stack<int> & order) {


	visited[si] = true;

	for (int j = 0; j < n; j++) {
		if (j == si) {
			continue;
		}

		if (edges[si][j] && !visited[j]) {
			dfs(edges, n, j, visited, order);
		}
	}

	order.push(si);
}


void topological_sort(int ** edges, int n) {

	bool * visited = new bool [n];

	for (int i = 0; i < n; i++) {
		visited[i] = false;
	}

	stack<int> order;

	for (int i = 0; i < n; i++)
	{
		if (!visited[i])
			dfs(edges, n, i, visited, order);
	}

	while (!order.empty()) {
		cout << order.top() << " ";
		order.pop();
	}

	delete [] visited;
	return;
}

int main() {

	int n, m;
	cin >> n >> m;

	if (!n)
		return 0;

	int ** edges = new int *[n];

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
	}

	topological_sort(edges, n);

	for (int i = 0; i < n; i++) {
		delete [] edges[i];
	}

	delete [] edges;

	return 0;
}