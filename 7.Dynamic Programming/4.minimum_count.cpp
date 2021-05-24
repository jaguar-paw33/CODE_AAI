/*

Given an integer N, find and return the count of minimum numbers required to represent N as a sum of squares.
That is, if N is 4, then we can represent it as : {1^2 + 1^2 + 1^2 + 1^2} and {2^2}. The output will be 1, as 1 is the minimum count of numbers required to represent N as sum of squares.

Input format :
The first and the only line of input contains an integer value, 'N'.

Output format :
Print the minimum count of numbers required.

Constraints :
0 <= n <= 10 ^ 4

Time Limit: 1 sec

Sample Input 1 :
12
Sample Output 1 :
3

Explanation of Sample Output 1 :

12 can be represented as :

A) (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2)

B) (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2)  + (2 ^ 2)

C) (1^2) + (1^2) + (1^2) + (1^2) + (2 ^ 2) + (2 ^ 2)

D) (2 ^ 2) + (2 ^ 2) + (2 ^ 2)

As we can see, the output should be 3.

Sample Input 2 :
9
Sample Output 2 :
1

*/

#include<bits/stdc++.h>
using namespace std;

int min_count_rec(int n) {
	if (n <= 0)
		return 0;
	if (n == 1 || n == 2 || n == 3)
		return n;
	int ans = INT_MAX;
	for (int i = 1; i <= sqrt(n); i++) {
		ans = min(ans, min_count_rec(n - (i * i)));
	}
	return ans + 1;
}

int min_count_mem(int n, int * mem) {
	if (n <= 0)
		return 0;
	if (n == 1 || n == 2 || n == 3)
		return n;
	if (mem[n] == -1) {
		mem[n] = INT_MAX;
		for (int i = 1; i <= sqrt(n); i++) {
			mem[n] = min(mem[n], min_count_mem(n - (i * i), mem));
		}
		mem[n] += 1;
	}
	return mem[n];
}

int min_count_dp(int n) {

	int * dp = new int [n + 1];

	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 3;

	for (int i = 4; i <= n; i++) {
		dp[i] = INT_MAX;
		for (int j = 1; j <= sqrt(i); j++) {
			dp[i] = min(dp[i], dp[i - (j * j)]);
		}
		dp[i] += 1;
	}

	return dp[n];
}

int main() {
	int n;
	cin >> n;
	cout << min_count_rec(n) << endl;
	int mem[n + 1];
	memset(mem, -1, sizeof(int) * (n + 1));
	cout << min_count_mem(n, mem) << endl;
	cout << min_count_dp(n) << endl;
	return 0;
}