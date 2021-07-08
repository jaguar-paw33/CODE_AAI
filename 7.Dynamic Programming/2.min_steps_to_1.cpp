/*

Given a positive integer 'n', find and return the minimum number of steps that 'n' has to take to get reduced to 1. You can perform any one of the following 3 steps:

1.) Subtract 1 from it. (n = n - ­1) ,
2.) If its divisible by 2, divide by 2.( if n % 2 == 0, then n = n / 2 ) ,
3.) If its divisible by 3, divide by 3. (if n % 3 == 0, then n = n / 3 ).

Write brute-force recursive solution for this.

Input format :
The first and the only line of input contains an integer value, 'n'.

Output format :
Print the minimum number of steps.

Constraints :
1 <= n <= 200

Time Limit: 1 sec

Sample Input 1 :
4
Sample Output 1 :
2
Explanation of Sample Output 1 :
For n = 4
Step 1 :  n = 4 / 2  = 2
Step 2 : n = 2 / 2  =  1

Sample Input 2 :
7
Sample Output 2 :
3
Explanation of Sample Output 2 :
For n = 7
Step 1 :  n = 7 ­- 1 = 6
Step 2 : n = 6  / 3 = 2
Step 3 : n = 2 / 2 = 1

*/


#include<bits/stdc++.h>
using namespace std;

int min_steps_to_1_rec(int n) {
	if (n <= 1)
		return 0;
	if (n == 2 || n == 3)
		return 1;

	int ways = min_steps_to_1_rec(n - 1);

	if (n % 2 == 0)
		ways = min(ways, min_steps_to_1_rec(n / 2));

	if (n % 3 == 0)
		ways = min(ways, min_steps_to_1_rec(n / 3));

	return ways + 1;
}

int min_steps_to_1_mem(int n, int * mem) {
	if (n <= 1)
		return 0;
	if (n == 2 || n == 3)
		return 1;

	if (mem[n] == -1) {
		mem[n] = min_steps_to_1_mem(n - 1, mem);
		if (n % 2 == 0)
			mem[n] = min(mem[n], min_steps_to_1_mem(n / 2, mem));
		if (n % 3 == 0)
			mem[n] = min(mem[n], min_steps_to_1_mem(n / 3, mem));
		mem[n] += 1;
	}
	return mem[n];
}

int min_steps_to_1_dp(int n) {
	int * dp = new int [n + 1];

	dp[0] = 0;
	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 1;

	for (int i = 4; i <= n; i++) {

		dp[i] = dp[i - 1];

		if (i % 2 == 0)
			dp[i] = min(dp[i], dp[i / 2]);

		if (i % 3 == 0)
			dp[i] = min(dp[i], dp[i / 3]);
		dp[i] += 1;
	}

	return dp[n];
}

int main() {
	int n;
	cin >> n;

	cout << min_steps_to_1_rec(n) << endl;

	int mem[n + 1];
	memset(mem, -1, sizeof(int) * (n + 1));

	cout << min_steps_to_1_mem(n, mem) << endl;

	cout << min_steps_to_1_dp(n) << endl;

	return 0;
}