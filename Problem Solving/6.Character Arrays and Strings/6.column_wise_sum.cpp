/*

Given a 2D integer array of size M*N, find and print the sum of ith column elements separated by space.

Input Format :
Line 1 : Two integers M and N (separated by space)
Next M lines : ith row elements (separated by space)

Output Format :
Sum of every ith column elements (separated by space)

Constraints :
1 <= M, N <= 10^3

Sample Input :
4 2
1 2
3 4
5 6
7 8

Sample Output :
16 20

*/

#include<bits/stdc++.h>
using namespace std;

void column_wise_sum(int ** arr, int n, int m) {

	int * ans = new int[m];

	for (int j = 0; j < m; j++) {
		int s = 0;
		for (int i = 0; i < n; i++) {
			s += arr[i][j];
		}
		ans[j] = s;
	}

	for (int i = 0; i < m; i++) {
		cout << ans[i] << " ";
	}

	delete [] ans;
}

int main() {
	int n, m;
	cin >> n >> m;

	int ** arr = new int*[n];
	for (int i = 0; i < n; i++) {
		arr[i] = new int [m];

		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	column_wise_sum(arr, n, m);

	return 0;
}