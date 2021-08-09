/*

Given a m * n matrix mat of ones (representing soldiers) and zeros (representing civilians), return the indexes of the k weakest rows in the matrix ordered from the weakest to the strongest.

A row i is weaker than row j, if the number of soldiers in row i is less than the number of soldiers in row j, or they have the same number of soldiers but i is less than j. Soldiers are always stand in the frontier of a row, that is, always ones may appear first and then zeros.



Example 1:


Input: mat =

[[1,1,0,0,0],

 [1,1,1,1,0],

 [1,0,0,0,0],

 [1,1,0,0,0],

 [1,1,1,1,1]],

k = 3

Output: [2,0,3]

Explanation:

The number of soldiers for each row is:

row 0 -> 2

row 1 -> 4

row 2 -> 1

row 3 -> 2

row 4 -> 5

Rows ordered from the weakest to the strongest are [2,0,3,1,4]


Example 2:



Input: mat =

[[1,0,0,0],

 [1,1,1,1],

 [1,0,0,0],

 [1,0,0,0]],

k = 2

Output: [0,2]

Explanation:

The number of soldiers for each row is:

row 0 -> 1

row 1 -> 4

row 2 -> 1

row 3 -> 1

Rows ordered from the weakest to the strongest are [0,2,3,1]

Constraints:


m == mat.length

n == mat[i].length

2 <= n, m <= 100

1 <= k <= m

matrix[i][j] is either 0 or 1.



Level: Easy

Problem Practice link: https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/

*/

#include<bits/stdc++.h>
using namespace std;

bool comp(pair<int, int> a, pair<int, int> b) {
	return a.second <= b.second;
}

// rows - m columns - n
// Time Complexity - O(m(n+logm)) Space Complexity - O(m)
vector<int> kWeakestRows1(vector<vector<int>>& matrix, int k) {

	int ei = matrix[0].size() - 1;
	int j = ei;

	map<int, vector<int>> m;

	for (int i = 0; i < matrix.size();) {

		if (matrix[i][j]) {
			m[j + 1].push_back(i);
			i++;
			j = ei;
		} else {
			j--;
		}

		if (j == -1)
		{
			m[0].push_back(i);
			j = ei;
			i++;
		}
	}

	vector<int> ans;

	for (auto p : m) {
		vector<int> v = p.second;
		for (auto idx : v) {
			ans.push_back(idx);
			k--;
			if (!k)
				return ans;
		}
	}

	return ans;
}

// rows - m columns - n
// Using Binary Search Time Complexity - O(m(logn+logm)) Space Complexity - O(m)
int first_zero(vector<vector<int>> & matrix, int i, int si, int ei) {
	int idx = ei + 1;
	while (si <= ei) {

		int mid = si + (ei - si) / 2;

		if (matrix[i][mid] == 0) {
			idx = mid;
			ei = mid - 1;
		} else {
			si = mid + 1;
		}
	}
	return idx;
}

vector<int> kWeakestRows2(vector<vector<int>>& matrix, int k) {

	int ei = matrix[0].size() - 1;
	int j = ei;

	map<int, vector<int>> m;

	for (int i = 0; i < matrix.size(); i++) {

		if (matrix[i][j]) {
			m[j + 1].push_back(i);
		} else {
			int idx = first_zero(matrix, i, 0, j);
			m[idx].push_back(i);
		}
	}

	vector<int> ans;

	for (auto p : m) {
		vector<int> v = p.second;
		for (auto idx : v) {
			ans.push_back(idx);
			k--;
			if (!k)
				return ans;
		}
	}

	// Fetching of k-smallest indices can also be done based on the no. of soldiers can be done using heap in O(mlogk) time
	// which is less than the current time complexity of O(mlogm) but in worst case our k can also be m.

	return ans;

}

int main() {
	int m, n;

	cin >> m >> n;

	int rows = m, cols = n;

	int v;

	vector<vector<int>> matrix;

	while (rows--) {
		cols = n;
		vector<int> row;
		while (cols--) {
			cin >> v;
			row.push_back(v);
		}
		matrix.push_back(row);
	}

	int k;
	cin >> k;

	vector<int> ans1 = kWeakestRows1(matrix, k);

	for (int i = 0; i < ans1.size(); i++) {
		cout << ans1[i] << " ";
	}

	vector<int> ans2 = kWeakestRows2(matrix, k);

	for (int i = 0; i < ans2.size(); i++) {
		cout << ans2[i] << " ";
	}

	return 0;
}