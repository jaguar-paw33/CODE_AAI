/*

You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).

You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

Example 1:


Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [[7,4,1],[8,5,2],[9,6,3]]
Example 2:


Input: matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
Output: [[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]
Example 3:

Input: matrix = [[1]]
Output: [[1]]
Example 4:

Input: matrix = [[1,2],[3,4]]
Output: [[3,1],[4,2]]


Constraints:

matrix.length == n
matrix[i].length == n
1 <= n <= 20
-1000 <= matrix[i][j] <= 1000

*/


#include<bits/stdc++.h>
using namespace std;

void reverse(vector<vector<int>> & matrix) {

	for (int i = 0; i < matrix.size(); i++) {
		vector<int> row = matrix[i];
		for (int j = 0, k = row.size() - 1; j < k; j++, k--) {
			int temp = matrix[i][j];
			matrix[i][j] = matrix[i][k];
			matrix[i][k] = temp;
		}
	}

}

void transpose(vector<vector<int>> & matrix) {
	for (int i = 0; i < matrix.size(); i++) {
		vector<int> row = matrix[i];
		for (int j = 0; j < row.size(); j++) {
			if (i < j) {
				int temp = matrix[i][j];
				matrix[i][j] = matrix[j][i];
				matrix[j][i] = temp;
			}
		}
	}
}

void rotate_by_90_clockwise(vector<vector<int>> & matrix) {
	transpose(matrix);
	reverse(matrix);
}

void rotate_by_90_anticlockwise(vector<vector<int>> & matrix) {
	reverse(matrix);
	transpose(matrix);
}

int main() {
	int n, m;
	cin >> n >> m;

	// The solution below is for square matrices.
	// For a non-square matrix we need to create a new matrix since the tranpose can't be done on the same matrix

	vector<vector<int>> matrix;

	int v;

	int rows = n;
	int cols = m;

	while (rows--) {
		vector<int> row;
		cols = m;
		while (cols--) {
			cin >> v;
			row.push_back(v);
		}
		matrix.push_back(row);
	}

	rotate_by_90_clockwise(matrix);

	for (int i = 0; i < matrix.size(); i++) {
		vector<int> row = matrix[i];
		for (int j = 0; j < row.size(); j++) {
			cout << row[j] << " ";
		}
		cout << endl;
	}

	// rotate_by_90_anticlockwise(matrix);

	// for (int i = 0; i < matrix.size(); i++) {
	// 	vector<int> row = matrix[i];
	// 	for (int j = 0; j < row.size(); j++) {
	// 		cout << row[j] << " ";
	// 	}
	// 	cout << endl;
	// }


	return 0;
}

