/*

Given two strings s and t of lengths m and n respectively, find the edit distance between the strings.

Edit Distance

Edit Distance of two strings is minimum number of operations required to make one string equal to other. In order to do so you can perform any of the following three operations only :

1. Delete a character
2. Replace a character with another one
3. Insert a character

Note : Strings don't contain spaces

Input Format :
The first line of input contains a string, that denotes the value of s. The following line contains a string, that denotes the value of t.

Output Format :
The first and only line of output contains the edit distance value between the given strings.

Constraints :
1<= m,n <= 10
Time Limit: 1 second

Sample Input 1 :
abc
dc
Sample Output 1 :
2

*/

#include<bits/stdc++.h>
using namespace std;

int edit_distance_rec(string a, string b) {
	if (!a.size() || !b.size())
		return (!a.size() ? b.size() : a.size());
	if (a[0] == b[0]) {
		return edit_distance_rec(a.substr(1), b.substr(1));
	} else {
		int m1 = edit_distance_rec(a.substr(1), b);
		int m2 = edit_distance_rec(a.substr(1), b.substr(1));
		int m3 = edit_distance_rec(a, b.substr(1));
		return min(m1, min(m2, m3)) + 1;
	}
}

int edit_distance_mem(string a, string b, int ** mem) {
	int s1 = a.size(), s2 = b.size();
	if (!s1 || !s2)
		return (!s1 ? s2 : s1);

	if (mem[s1][s2] == -1) {
		if (a[0] == b[0]) {
			mem[s1][s2] = edit_distance_mem(a.substr(1), b.substr(1), mem);
		} else {
			int m1 = edit_distance_mem(a.substr(1), b, mem);
			int m2 = edit_distance_mem(a.substr(1), b.substr(1), mem);
			int m3 = edit_distance_mem(a, b.substr(1), mem);
			mem[s1][s2] = min(m1, min(m2, m3)) + 1;
		}
	}
	return mem[s1][s2];
}


int edit_distance_dp(string a, string b) {

	int s1 = a.size(), s2 = b.size();

	int ** dp = new int * [s1 + 1];
	for (int i = 0; i < s1 + 1; i++) {
		dp[i] = new int [s2 + 1];
	}

	for (int i = 0; i < s1 + 1; i++) {
		dp[i][0] = i;
	}
	for (int j = 0; j < s2 + 1; j++) {
		dp[0][j] = j;
	}

	for (int i = 1; i < s1 + 1; i++) {
		for (int j = 1; j < s2 + 1; j++) {
			if (a[i - 1] == b[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1];
			} else {
				int m1 = dp[i - 1][j];
				int m2 = dp[i - 1][j - 1];
				int m3 = dp[i][j - 1];
				dp[i][j] = min(m1, min(m2, m3)) + 1;
			}
		}
	}

	return dp[s1][s2];

}

int main() {
	string a, b;
	cin >> a >> b;

	cout << edit_distance_rec(a, b) << endl;

	int s1 = a.size(), s2 = b.size();
	int ** mem = new int * [s1 + 1];
	for (int i = 0; i < s1 + 1; i++) {
		mem[i] = new int [s2 + 1];
		memset(mem[i], -1, sizeof(int) * (s2 + 1));
	}

	cout << edit_distance_mem(a, b, mem) << endl;

	cout << edit_distance_dp(a, b) << endl;

	for (int i = 0; i < s1 + 1; i++) {
		delete [] mem[i];
	}
	delete [] mem;

	return 0;
}