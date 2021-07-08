#include<bits/stdc++.h>
using namespace std;

int nth_fibonacci_rec(int n) {
	if (n == 0 || n == 1)
		return n;
	return nth_fibonacci_rec(n - 1) + nth_fibonacci_rec(n - 2);
}

int nth_fibonacci_mem(int n, int * mem) {
	if (n == 0 || n == 1)
		return n;

	if (mem[n] != -1) {
		return mem[n];
	} else {
		mem[n] = nth_fibonacci_mem(n - 1, mem) + nth_fibonacci_mem(n - 2, mem);
		return mem[n];
	}
}

int nth_fibonacci_dp(int n) {
	int * dp = new int [n + 1];

	dp[0] = 0;
	dp[1] = 1;

	for (int i = 2; i < n + 1; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	return dp[n];
}

int main() {
	int n;
	cin >> n;

	cout << nth_fibonacci_rec(n) << endl;

	int mem[n + 1];
	memset(mem, -1, sizeof(int) * (n + 1));

	cout << nth_fibonacci_mem(n, mem) << endl;

	cout << nth_fibonacci_dp(n) << endl;

	return 0;
}