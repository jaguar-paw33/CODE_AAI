#include<bits/stdc++.h>
using namespace std;


long long solve(int n, int * a, int x) {
	long long dp[n + 1];
	int ep = 0;
	int op = 0;
	dp[0] = 0;

	for (int i = 1; i < n + 1; i++) {
		if (a[i - 1] % 2) {
			dp[i] = max(dp[ep] - x, dp[op]) + a[i - 1];
			op = i;
		} else {
			dp[i] = max(dp[ep], dp[op] - x) + a[i - 1];
			ep = i;
		}
	}

	return dp[n];
}

int main() {
	int n, x;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	cin >> x;

	cout << solve(n, a, x) << endl;

	return 0;
}