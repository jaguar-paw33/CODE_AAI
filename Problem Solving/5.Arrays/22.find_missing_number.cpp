/*

Given an array of size n consisting of numbers from 1 to n. There is one number missing in that array.
Finf that number.

Example:
1. n = 10 and arr = [1,2,3,5,6,4,7,9,6,10]

*/

#include<bits/stdc++.h>
using namespace std;

int find_missing(int * arr, int n) {
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		ans ^= i;
	}
	for (int i = 0; i < n - 1; i++) {
		ans ^= arr[i];
	}

	return ans;
}

int main() {
	int n;
	cin >> n;

	int * arr = new int [n - 1];
	for (int i = 0; i < n - 1; i++) {
		cin >> arr[i];
	}

	cout << find_missing(arr, n) << endl;

	return 0;
}