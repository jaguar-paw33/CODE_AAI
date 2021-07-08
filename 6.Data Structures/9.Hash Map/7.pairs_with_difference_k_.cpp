/*

You are given with an array of integers and an integer K. You have to find and print the count of all such pairs which have difference K.

Note: Take absolute difference between the elements of the array.

Input Format:
The first line of input contains an integer, that denotes the value of the size of the array. Let us denote it with the symbol n.
The following line contains n space separated integers, that denote the value of the elements of the array.
The following line contains an integer, that denotes the value of K.

Output format :
The first and only line of output contains count of all such pairs which have an absolute difference of K.

Constraints :
0 <= n <= 10^4
Time Limit: 1 sec

Sample Input 1 :
4
5 1 2 4
3
Sample Output 1 :
2

Sample Input 2 :
4
4 4 4 4
0
Sample Output 2 :
6

*/

#include<bits/stdc++.h>
using namespace std;

int pairs_with_difference_k(int * arr, int n, int k) {

	unordered_map<int, int> m;

	for (int i = 0; i < n; i++) {
		m[arr[i]]++;
	}

	int count = 0;

	if (k == 0) {
		for (int i = 0; i < n; i++) {
			if (m[arr[i]]) {
				count += (m[arr[i]] * (m[arr[i]] - 1)) / 2;
				m[arr[i]] = 0;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		if (m[arr[i] - k]) {
			count += m[arr[i] - k];
		}
	}

	return count;

}

int main() {
	int n;
	cin >> n;
	int * arr = new int [n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int k;
	cin >> k;
	cout << pairs_with_difference_k(arr, n, k) << endl;
	delete [] arr;
	return 0;
}