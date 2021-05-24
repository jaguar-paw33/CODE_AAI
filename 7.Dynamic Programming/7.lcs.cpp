#include<bits/stdc++.h>
using namespace std;

int lcs_rec(string a, string b) {
	if (!a.size() || !b.size())
		return 0;
	if (a[0] == b[0])
		return 1 + lcs_rec(a.substr(1), b.substr(1));
	else {
		int l1 = lcs_rec(a.substr(1), b);
		int l2 = lcs_rec(a, b.substr(1));
		return max(l1, l2);
	}
}

int lcs_mem(string a, string b, int ** mem) {
	int s1 = a.size(), s2 = b.size();
	if (!s1 || !s2)
		return 0;
	if (mem[s1][s2] == -1) {
		if (a[0] == b[0])
			mem[s1][s2] = 1 + lcs_mem(a.substr(1), b.substr(1), mem);
		else {
			int l1 = lcs_mem(a.substr(1), b, mem);
			int l2 = lcs_mem(a, b.substr(1), mem);
			mem[s1][s2] = max(l1, l2);
		}
	}
	return mem[s1][s2];
}

int lcs_dp(string a, string b) {
	int s1 = a.size(), s2 = b.size();
	int ** dp = new int * [s1 + 1];
	for (int i = 0; i < s1 + 1; i++) {
		dp[i] = new int [s2 + 1];
	}

	for (int i = 0; i < s1 + 1; i++) {
		dp[i][0] = 0;
	}

	for (int j = 0; j < s2 + 1; j++) {
		dp[0][j] = 0;
	}

	for (int i = 1; i < s1 + 1; i++) {
		for (int j = 1; j < s2 + 1; j++) {
			if (a[i - 1] == b[j - 1]) {
				dp[i][j] = 1 + dp[i - 1][j - 1];
			} else {
				dp[i][j] = max(dp[i - 1][j], max(dp[i - 1][j - 1], dp[i][j - 1]));
			}
		}
	}
	return dp[s1][s2];
}

int main() {
	string a, b;
	cin >> a >> b;

	cout << lcs_rec(a, b) << endl;

	int s1 = a.size(), s2 = b.size();
	int ** mem = new int * [s1 + 1];
	for (int i = 0; i < s1 + 1; i++) {
		mem[i] = new int [s2 + 1];
		memset(mem[i], -1, sizeof(int) * (s2 + 1));
	}
	cout << lcs_mem(a, b, mem) << endl;

	cout << lcs_dp(a, b) << endl;

	for (int i = 0; i < s1 + 1; i++) {
		delete [] mem[i];
	}
	delete [] mem;

	return 0;
}