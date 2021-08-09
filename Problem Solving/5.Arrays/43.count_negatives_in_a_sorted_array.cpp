/*

Given a m * n matrix grid which is sorted in non-increasing order both row-wise and column-wise.

Return the number of negative numbers in grid.

Example 1:


Input: grid = [[4,3,2,-1],[3,2,1,-1],[1,1,-1,-2],[-1,-1,-2,-3]]

Output: 8

Explanation: There are 8 negatives number in the matrix.



Example 2:





Input: grid = [[3,2],[1,0]]

Output: 0



Example 3:





Input: grid = [[1,-1],[-1,-1]]

Output: 3



Example 4:





Input: grid = [[-1]]

Output: 1

Constraints:



m == grid.length

n == grid[i].length

1 <= m, n <= 100

-100 <= grid[i][j] <= 100


Level: Easy

Practice Link: https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/

*/

#include<bits/stdc++.h>
using namespace std;

// This problem can easily be solved in O(m*n) by traversing through each of the cell but this complexity can further be reduced


// Time Complexity - O(m+n)
int count_negatives(vector<vector<int>> matrix) {
	int count = 0, j = 0;
	for (int i = matrix.size() - 1; i >= 0 && j < matrix[i].size();) {
		if (matrix[i][j] < 0)
			count += matrix[i--].size() - j;
		else
			j++;
	}
	return count;
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

	cout << count_negatives(matrix) << endl;

	return 0;
}
