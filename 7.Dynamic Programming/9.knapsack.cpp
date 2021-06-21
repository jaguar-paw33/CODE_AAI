/*

A thief robbing a store can carry a maximal weight of W into his knapsack. There are N items, and i-th item weigh 'Wi' and the value being 'Vi.' What would be the maximum value V, that the thief can steal?

Input Format :
The first line of the input contains an integer value N, which denotes the total number of items.

The second line of input contains the N number of weights separated by a single space.

The third line of input contains the N number of values separated by a single space.

The fourth line of the input contains an integer value W, which denotes the maximum weight the thief can steal.

Output Format :
Print the maximum value of V that the thief can steal.

Constraints :
1 <= N <= 20
1<= Wi <= 100
1 <= Vi <= 100

Time Limit: 1 sec

Sample Input 1 :
4
1 2 4 5
5 4 8 6
5
Sample Output 1 :
13

Sample Input 2 :
5
12 7 11 8 9
24 13 23 15 16
26
Sample Output 2 :
51

*/

#include<bits/stdc++.h>
using namespace std;

int knapsack_rec(int * weights, int * values, int n, int capacity) {
	if (!n || !capacity) {
		return 0;
	}
	if (weights[0] <= capacity) {
		int a = values[0] + knapsack_rec(weights + 1, values + 1, n - 1, capacity - weights[0]);
		int b = knapsack_rec(weights + 1, values + 1, n - 1, capacity);
		return max(a, b);
	} else {
		return knapsack_rec(weights + 1, values + 1, n - 1, capacity);
	}
}

int knapsack_mem(int * weights, int * values, int n, int capacity, int ** mem) {
	if (!n || !capacity) {
		return 0;
	}

	if (mem[n][capacity] == -1) {
		if (weights[0] <= capacity) {
			int a = values[0] + knapsack_mem(weights + 1, values + 1, n - 1, capacity - weights[0], mem);
			int b = knapsack_mem(weights + 1, values + 1, n - 1, capacity, mem);
			mem[n][capacity] = max(a, b);
		} else {
			mem[n][capacity] = knapsack_mem(weights + 1, values + 1, n - 1, capacity, mem);
		}
	}

	return mem[n][capacity];
}


int knapsack_dp(int * weights, int * values, int n, int capacity) {
	int ** dp = new int * [n + 1];
	for (int i = 0; i < n + 1; i++) {
		dp[i] = new int [capacity + 1];
	}

	for (int i = 0; i < n + 1; i++) {
		dp[i][0] = 0;
	}

	for (int j = 0; j < capacity + 1; j++) {
		dp[0][j] = 0;
	}

	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < capacity + 1; j++) {
			if (weights[i - 1] <= j) {
				dp[i][j] = max(dp[i - 1][j], values[i - 1] + dp[i - 1][j - weights[i - 1]]);
			} else {
				dp[i][j] = dp[i - 1][j];
			}
		}
	}

	return dp[n][capacity];
}

int knapsack_dp_space_optimized(int * weights, int * values, int n, int capacity) {
	int ** dp = new int * [2];
	for (int i = 0; i < 2; i++) {
		dp[i] = new int [capacity + 1];
	}

	for (int i = 0; i < 2; i++) {
		dp[i][0] = 0;
	}

	for (int j = 0; j < capacity + 1; j++) {
		dp[0][j] = 0;
	}

	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < capacity + 1; j++) {
			if (weights[i - 1] <= j) {
				dp[1][j] = max(dp[0][j], values[i - 1] + dp[0][j - weights[i - 1]]);
			} else {
				dp[1][j] = dp[0][j];
			}
		}
		for (int j = 0; j < capacity + 1; j++) {
			dp[0][j] = dp[1][j];
		}
	}

	return dp[1][capacity];
}


int main() {
	int n;
	cin >> n;

	int * weights = new int [n];
	for (int i = 0; i < n; i++) {
		cin >> weights[i];
	}

	int * values = new int [n];
	for (int i = 0; i < n; i++) {
		cin >> values[i];
	}

	int capacity;
	cin >> capacity;

	cout << knapsack_rec(weights, values, n, capacity) << endl;

	int ** mem = new int * [n + 1];

	for (int i = 0; i < n + 1; i++) {
		mem[i] = new int [capacity + 1];
		memset(mem[i], -1, sizeof(int) * (capacity + 1));
	}

	cout << knapsack_mem(weights, values, n, capacity, mem) << endl;

	cout << knapsack_dp(weights, values, n, capacity) << endl;

	cout << knapsack_dp_space_optimized(weights, values, n, capacity) << endl;

	for (int i = 0; i < n + 1; i++) {
		delete [] mem[i];
	}
	delete [] mem;

	delete [] weights;
	delete [] values;

	return 0;
}

