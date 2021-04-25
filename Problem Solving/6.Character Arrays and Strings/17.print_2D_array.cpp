/*

Given a 2D integer array with n rows and m columns. Print the 0th row from input n times, 1st row n-1 times…..(n-1)th row will be printed 1 time.

Input format :

Line 1 : No of rows(n) & No of columns(m) (separated by space)

Line 2 : Row 1 elements (separated by space)

Line 3 : Row 2 elements (separated by space)

Line 4 : and so on

Sample Input :
3 3
1    2    3
4    5    6
7    8    9

Sample Output :
1    2    3
1    2    3
1    2    3
4    5    6
4    5    6
7    8    9

*/

#include<bits/stdc++.h>
using namespace std;

void print_formatted(int ** arr, int n, int m) {
	for (int i = 0; i < n; i++) {
		int print_count = n - i;
		while (print_count--) {
			for (int j = 0; j < m; j++) {
				cout << arr[i][j] << " ";
			}
			cout << endl;
		}
	}
}

int main() {
	int n, m;
	cin >> n >> m;

	int ** arr = new int * [n];

	for (int i = 0; i < n; i++) {
		arr[i] = new int [m];

		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}

	}

	print_formatted(arr, n, m);

	for (int i = 0; i < n; i++) {
		delete [] arr[i];
	}

	delete [] arr;

	return 0;

}