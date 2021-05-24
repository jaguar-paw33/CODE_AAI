#include<iostream>
#include<vector>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	vector<vector<int>> list;

	for (int i = 0; i < n; i++) {
		vector<int> v;
		list.push_back(v);
	}

	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		list[u].push_back(v);
	}

	for (int i = 0; i < n; i++) {
		vector<int> v = list[i];
		cout << i << " : ";
		for (int j = 0; j < v.size(); j++) {
			cout << v[j] << " ";
		}
		cout << endl;
	}

	return 0;


}