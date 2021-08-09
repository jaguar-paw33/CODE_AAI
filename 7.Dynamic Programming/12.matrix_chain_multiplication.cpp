#include<bits/stdc++.h>
using namespace std;


/*

	Think in terms of matrices and not in terms of indices and to build the logic simply think
	of places where cut can be done.

*/


int mcm_rec(int * dims, int start_matrix, int end_matrix) {

	if (start_matrix == end_matrix)
		return 0;

	if (end_matrix == (1 + start_matrix)) {
		return dims[start_matrix - 1] * dims[start_matrix] * dims[end_matrix];
	}

	int ans = INT_MAX;

	for (int i = start_matrix; i < end_matrix; i++) {
		ans = min(ans, mcm_rec(dims, start_matrix, i) + dims[start_matrix - 1] * dims[i] * dims[end_matrix] + mcm_rec(dims, i + 1, end_matrix));
	}

	return ans;

}




int mcm_mem(int * dims, int start_matrix, int end_matrix, int ** mem) {

	// i,j cell of mem corresponds to ith matrix to jth matrix.

	if (start_matrix == end_matrix)
		return 0;

	if (end_matrix == (1 + start_matrix))
		return dims[start_matrix - 1] * dims[start_matrix] * dims[end_matrix];

	if (mem[start_matrix][end_matrix] != -1)
		return mem[start_matrix][end_matrix];

	mem[start_matrix][end_matrix] = INT_MAX;

	for (int i = start_matrix; i < end_matrix; i++) {
		mem[start_matrix][end_matrix] = min(mem[start_matrix][end_matrix], mcm_mem(dims, start_matrix, i, mem) + dims[start_matrix - 1] * dims[i] * dims[end_matrix] + mcm_mem(dims, i + 1, end_matrix, mem));
	}

	return mem[start_matrix][end_matrix];
}





int mcm_dp(int * dims, int n) {

	if (n <= 1)
		return 0;

	int ** dp = new int * [n + 1];
	for (int i = 0; i < n + 1; i++) {
		dp[i] = new int [n + 1];
		for (int j = 0; j < n + 1; j++) {
			if (j <= i) {
				dp[i][j] = 0;
			}
		}
	}

	for (int l = 2; l <= n; l++) { // Matrix Chain Length
		for (int start_matrix = 1; start_matrix <= n - l + 1; start_matrix++) {

			int end_matrix = l + start_matrix - 1;

			dp[start_matrix][end_matrix] = INT_MAX;

			for (int k = start_matrix; k < end_matrix; k++) {
				dp[start_matrix][end_matrix] = min(dp[start_matrix][end_matrix], (dp[start_matrix][k] + dims[start_matrix - 1] * dims[k] * dims[end_matrix] + dp[k + 1][end_matrix]));
			}
		}
	}

	return dp[1][n];
}

int main() {
	int n;
	cin >> n;

	int * dims = new int [n];
	for (int i = 0; i < n; i++) {
		cin >> dims[i];
	}


	// Passing Number of Matrices as an Argument


	cout << mcm_rec(dims, 1, n - 1) << endl;

	int ** mem = new int * [n];
	for (int i = 0; i < n; i++) {
		mem[i] = new int [n];
		for (int j = 0; j < n ; j++) {
			if (i == 0 || j == 0)
				mem[i][j] = 0;
			mem[i][j] = -1;
		}
	}

	cout << mcm_mem(dims, 1, n - 1, mem) << endl;

	cout << mcm_dp(dims, n - 1) << endl;

	return 0;
}