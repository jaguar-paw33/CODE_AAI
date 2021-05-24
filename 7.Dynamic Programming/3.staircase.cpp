/*

A child runs up a staircase with 'n' steps and can hop either 1 step, 2 steps or 3 steps at a time. Implement a method to count and return all possible ways in which the child can run-up to the stairs.

Input format :
The first and the only line of input contains an integer value, 'n', denoting the total number of steps.

Output format :
Print the total possible number of ways.

Constraints :
0 <= n <= 10 ^ 4

Time Limit: 1 sec

Sample Input 1:
4
Sample Output 1:
7

Sample Input 2:
10
Sample Output 2:
274

*/

#include<bits/stdc++.h>
using namespace std;

long ways_rec(int n) {
	if (n <= 1)
		return 1;
	if (n == 2)
		return 2;
	if (n == 3)
		return 4;
	return ways_rec(n - 1) + ways_rec(n - 2) + ways_rec(n - 3);
}

long ways_mem(int n, long * mem) {
	if (n <= 1)
		return 1;
	if (n == 2)
		return 2;
	if (n == 3)
		return 4;

	if (mem[n] == -1) {
		mem[n] = ways_mem(n - 1, mem) + ways_mem(n - 2, mem) + ways_mem(n - 3, mem);
	}
	return mem[n];
}

long ways_dp(int n) {
	long * dp = new long [n + 1];
	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;

	for (int i = 4; i < n + 1; i++) {
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
	}
	return dp[n];
}

int main() {
	int n;
	cin >> n;
	cout << ways_rec(n) << endl;
	long mem[n + 1];
	memset(mem, -1, sizeof(long) * (n + 1));
	cout << ways_mem(n, mem) << endl;
	cout << ways_dp(n) << endl;
	return 0;
}