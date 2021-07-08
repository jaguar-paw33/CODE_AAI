/*

Given an integer h, find the possible number of balanced binary trees of height h. You just need to return the count of possible binary trees which are balanced.
This number can be huge, so, return output modulus 10^9 + 7.
Write a simple recursive solution.

Input Format :
The first and only line of input contains an integer, that denotes the value of h. Here, h is the height of the tree.

Output Format :
The first and only line of output contains the count of balanced binary trees modulus 10^9 + 7.

Constraints :
1 <= h <= 24
Time Limit: 1 sec

Sample Input 1:
3
Sample Output 1:
15

Sample Input 2:
4
Sample Output 2:
315

*/

#include<bits/stdc++.h>
using namespace std;

long num_balanced_BSTs_rec(int n) {
	if (n == 1)
		return 1;
	if (n == 2)
		return 3;
	long mod = pow(10, 9) + 7;
	long a = num_balanced_BSTs_rec(n - 1) % mod;
	long b = num_balanced_BSTs_rec(n - 2) % mod;
	long ans = (2 * ((a * b) % mod) + (a * a) % mod) % mod;
	return ans;
}

long num_balanced_BSTs_mem(int n, long * mem) {
	if (n == 1)
		return 1;
	if (n == 2)
		return 3;
	if (mem[n] == -1) {
		long mod = pow(10, 9) + 7;
		long a = num_balanced_BSTs_mem(n - 1, mem) % mod;
		long b = num_balanced_BSTs_mem(n - 2, mem) % mod;
		mem[n] = (2 * ((a * b) % mod) + (a * a) % mod) % mod;
	}
	return mem[n];
}

long num_balanced_BSTs_dp(int n) {
	long * dp = new long [n + 1];
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 3;
	for (int i = 3; i <= n; i++) {
		long mod = pow(10, 9) + 7;
		long a = dp[i - 1] % mod;
		long b = dp[i - 2] % mod;
		dp[i] = (2 * ((a * b) % mod) + (a * a) % mod) % mod;
	}
	return dp[n];
}


int main() {
	int n;
	cin >> n;
	cout << num_balanced_BSTs_rec(n) << endl;
	long mem[n + 1];
	memset(mem, -1, sizeof(long) * (n + 1));
	cout << num_balanced_BSTs_mem(n, mem) << endl;
	cout << num_balanced_BSTs_dp(n) << endl;
	return 0;
}