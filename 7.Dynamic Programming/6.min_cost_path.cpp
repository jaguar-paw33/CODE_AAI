/*

An integer matrix of size (M x N) has been given. Find out the minimum cost to reach from the cell (0, 0) to (M - 1, N - 1).

From a cell (i, j), you can move in three directions:

1. ((i + 1),  j) which is, "down"
2. (i, (j + 1)) which is, "to the right"
3. ((i+1), (j+1)) which is, "to the diagonal"

The cost of a path is defined as the sum of each cell's values through which the route passes.

Input format :
The first line of the test case contains two integer values, 'M' and 'N', separated by a single space. They represent the 'rows' and 'columns' respectively, for the two-dimensional array/list.

The second line onwards, the next 'M' lines or rows represent the ith row values.

Each of the ith row constitutes 'N' column values separated by a single space.

Output format :
Print the minimum cost to reach the destination.

Constraints :
1 <= M <= 10 ^ 2
1 <= N <=  10 ^ 2

Time Limit: 1 sec

Sample Input 1 :
3 4
3 4 1 2
2 1 8 9
4 7 8 1
Sample Output 1 :
13

Sample Input 2 :
3 4
10 6 9 0
-23 8 9 90
-200 0 89 200
Sample Output 2 :
76

Sample Input 3 :
5 6
9 6 0 12 90 1
2 7 8 5 78 6
1 6 0 5 10 -4
9 6 2 -10 7 4
10 -2 0 5 5 7
Sample Output 3 :
18

*/

#include<bits/stdc++.h>
using namespace std;

int min_cost_path_rec(int ** arr, int rows, int cols) {
	if (rows == 0 || cols == 0) {
		return INT_MAX;
	}

	int a = min_cost_path_rec(arr, rows - 1, cols);
	int b = min_cost_path_rec(arr, rows - 1, cols - 1);
	int c = min_cost_path_rec(arr, rows, cols - 1);

	if (a == b && b == c && c == INT_MAX)
		return arr[rows - 1][cols - 1];

	int ans = min(a, min(b, c)) + arr[rows - 1][cols - 1];

	return ans;
}

int min_cost_path_mem(int ** arr, int rows, int cols, int ** mem) {

	if (rows == 0 || cols == 0)
		return INT_MAX;

	if (mem[rows][cols] == -1) {

		int a = min_cost_path_mem(arr, rows - 1, cols, mem);
		int b = min_cost_path_mem(arr, rows - 1, cols - 1, mem);
		int c = min_cost_path_mem(arr, rows, cols - 1, mem);

		if (a == b && b == c && c == INT_MAX)
			mem[rows][cols] = arr[rows - 1][cols - 1];
		else
			mem[rows][cols] =  min(a, min(b, c)) + arr[rows - 1][cols - 1];

	}

	return mem[rows][cols];
}


int min_cost_path_dp(int ** arr, int rows, int cols) {

	int ** dp = new int * [rows];

	for (int i = 0; i < rows; i++) {
		dp[i] = new int [cols];
	}

	dp[0][0] = arr[0][0];

	for (int i = 1; i < rows; i++) {
		dp[i][0] = dp[i - 1][0] + arr[i][0];
	}

	for (int j = 1; j < cols; j++) {
		dp[0][j] = dp[0][j - 1] + arr[0][j];
	}

	for (int i = 1; i < rows; i++) {
		for (int j = 1; j < cols; j++) {
			dp[i][j] = min(dp[i - 1][j], min(dp[i - 1][j - 1], dp[i][j - 1])) + arr[i][j];
		}
	}

	return dp[rows - 1][cols - 1];
}


int main() {

	int rows, cols;

	cin >> rows >> cols;

	int ** arr = new int * [rows];

	for (int i = 0; i < rows; i++) {
		arr[i] = new int [cols];
		for (int j = 0; j < cols; j++) {
			cin >> arr[i][j];
		}
	}

	cout << min_cost_path_rec(arr, rows, cols) << endl;


	int ** mem = new int * [rows + 1];
	for (int i = 0; i < rows + 1; i++) {
		mem[i] = new int [cols + 1];

		memset(mem[i], -1, sizeof(int) * (cols + 1));
	}
	cout << min_cost_path_mem(arr, rows, cols, mem) << endl;


	cout << min_cost_path_dp(arr, rows, cols) << endl;


	for (int i = 0; i < rows + 1; i++) {
		delete [] mem[i];
	}

	delete [] mem;

	for (int i = 0; i < rows; i++) {
		delete [] arr[i];
	}
	delete [] arr;

	return 0;
}