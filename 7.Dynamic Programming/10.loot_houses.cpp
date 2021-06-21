/*

A thief wants to loot houses. He knows the amount of money in each house. He cannot loot two consecutive houses. Find the maximum amount of money he can loot.

Input format :
The first line of input contains an integer value of 'n'. It is the total number of houses.

The second line of input contains 'n' integer values separated by a single space denoting the amount of money each house has.

Output format :
Print the the maximum money that can be looted.

Constraints :
0 <= n <= 10 ^ 4

Time Limit: 1 sec

Sample Input 1 :
6
5 5 10 100 10 5
Sample Output 1 :
110

Sample Input 2 :
6
10 2 30 20 3 50
Sample Output 2 :
90
Explanation of Sample Output 2 :
Looting first, third, and the last houses([10 + 30 + 50]) will result in the maximum loot, and all the other possible combinations would result in less than 90.

*/

#include<bits/stdc++.h>
using namespace std;

int max_loot_rec(int * money, int n) {
	if (n <= 0) {
		return 0;
	}
	int a = money[0] + max_loot_rec(money + 2, n - 2);
	int b = max_loot_rec(money + 1, n - 1);
	return max(a, b);
}

int max_loot_mem(int * money, int n, int * mem) {
	if (n <= 0)
		return 0;
	if (mem[n] == -1) {
		int a = money[0] + max_loot_mem(money + 2, n - 2, mem);
		int b = max_loot_mem(money + 1, n - 1, mem);
		mem[n] = max(a, b);
	}
	return mem[n];
}

int max_loot_dp(int * money, int n) {
	int * dp = new int [n + 1];
	dp[0] = 0;
	dp[1] = money[0];

	for (int i = 2; i < n + 1; i++) {
		dp[i] = max(money[i - 1] + dp[i - 2], dp[i - 1]);
	}
	return dp[n];
}

int main() {
	int n;
	cin >> n;

	int * money = new int [n];
	for (int i = 0; i < n; i++) {
		cin >> money[i];
	}

	cout << max_loot_rec(money, n) << endl;

	int * mem = new int [n + 1];
	memset(mem, -1, sizeof(int) * (n + 1));

	cout << max_loot_mem(money, n, mem) << endl;

	cout << max_loot_dp(money, n) << endl;

	delete [] mem;
	delete [] money;

	return 0;
}