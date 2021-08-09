/*

Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in-place.
Example 1:

Input:

[

  [1,1,1],

  [1,0,1],

  [1,1,1]

]

Output:

[

  [1,0,1],

  [0,0,0],

  [1,0,1]

]



Example 2:





Input:

[

  [0,1,2,0],

  [3,4,5,2],

  [1,3,1,5]

]

Output:

[

  [0,0,0,0],

  [0,4,5,0],

  [0,3,1,0]

]

Follow up:

A straight forward solution using O(mn) space is probably a bad idea.

A simple improvement uses O(m + n) space, but still not the best solution.

Could you devise a constant space solution?


Level: Medium

Problem Practice Link: https://leetcode.com/problems/set-matrix-zeroes/

*/

#include<bits/stdc++.h>
using namespace std;


//Time Complexity - O(mn) and Space Complexity - O(m+n)
void setZeros1(vector<vector<int>> & matrix) {

	unordered_set<int> rows;
	unordered_set<int> cols;

	for (int i = 0; i < matrix.size(); i++) {
		for (int j = 0; j < matrix[i].size(); j++) {
			if (!matrix[i][j]) {
				rows.insert(i);
				cols.insert(j);
			}
		}
	}

	for (int i = 0; i < matrix.size(); i++) {
		for (int j = 0; j < matrix[i].size(); j++) {

			if ((rows.find(i) != rows.end()) || (cols.find(j) != cols.end())) {
				matrix[i][j] = 0;
			}
		}
	}

}


// Time Complexity - O(mn) Space Complexity - O(1)
void setZeros2(vector<vector<int>> matrix) {

	if (!matrix.size())
		return;

	// Use the first row and first column as auxillary arrays

	bool rowFlag = false, colFlag = false;

	for (int i = 0; i < matrix.size(); i++) {
		if (!matrix[i][0])
			colFlag = true;
	}

	for (int j = 0; j < matrix[0].size(); j++) {
		if (!matrix[0][j])
			rowFlag = true;
	}

	for (int i = 1; i < matrix.size(); i++) {
		for (int j = 1; j < matrix[i].size(); j++) {
			if (!matrix[i][j]) {
				matrix[0][j] = 0;
				matrix[i][0] = 0;
			}
		}
	}

	for (int i = 1; i < matrix.size(); i++) {
		for (int j = 1; j < matrix[i].size(); j++) {
			if (!matrix[i][0] || !matrix[0][j]) {
				matrix[i][j] = 0;
			}
		}
	}

	if (rowFlag) {
		for (int j = 0; j < matrix[0].size(); j++) {
			matrix[0][j] = 0;
		}
	}

	if (colFlag) {
		for (int i = 0; i < matrix.size(); i++) {
			matrix[i][0] = 0;
		}
	}

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

	// setZeros1(matrix);
	setZeros2(matrix);

	for (int i = 0; i < matrix.size(); i++) {
		for (int j = 0; j < matrix[i].size(); j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}