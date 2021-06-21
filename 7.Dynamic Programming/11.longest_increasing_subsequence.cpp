/*

Given an array with N elements, you need to find the length of the longest subsequence in the given array such that all elements of the subsequence are sorted in strictly increasing order.

Input Format
The first line of input contains an integer N. The following line contains N space separated integers, that denote the value of elements of array.

Output Format
The first and only line of output contains the length of longest subsequence.

Constraints
1 <= N <= 10^3
Time Limit: 1 second

Sample Input 1 :
6
5 4 11 1 16 8
Sample Output 1 :
3
Sample Output Explanation
Length of longest subsequence is 3 i.e. (5,11,16) or (4,11,16).

Sample Input 2 :
3
1 2 2
Sample Output 2 :
2

*/

#include<bits/stdc++.h>
using namespace std;

int lis_rec(int * arr, int n) {

}

int lis_mem(int * arr, int n, int * mem) {

}

// int lis_dp(int * arr, int n) {

// }

int main() {
	int n;
	cin >> n;

	int * arr = new int [n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	cout << lis_rec(arr, n) << endl;

	// int * mem = new int [n + 1];
	// memset(mem, -1, sizeof(int) * (n + 1));

	// cout << lis_mem(arr, n, mem) << endl;

	// cout << lis_dp(arr, n) << endl;

	// delete [] mem;
	delete [] arr;

	return 0;
}

6
4 10 4 3 8 9