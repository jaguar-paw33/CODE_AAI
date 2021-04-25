/*

Given an array of length N and an integer x, you need to find and return the last index of integer x present in the array. Return -1 if it is not present in the array.
Last index means - if x is present multiple times in the array, return the index at which x comes last in the array.
You should start traversing your array from 0, not from (N - 1).

Do this recursively. Indexing in the array starts from 0.

Input Format :
Line 1 : An Integer N i.e. size of array
Line 2 : N integers which are elements of the array, separated by spaces
Line 3 : Integer x

Output Format :
last index or -1

Constraints :
1 <= N <= 10^3

Sample Input :
4
9 8 10 8
8

Sample Output :
3

*/

#include<bits/stdc++.h>
using namespace std;

int last_index(int * arr, int n, int key) {
	if (n <= 0)
		return -1;

	int index = last_index(arr + 1, n - 1, key);

	if (arr[0] == key) {
		if (index == -1)
			return 0;
	}

	return (index == -1 ? index : index + 1);
}

int main() {
	int n;
	cin >> n;

	int * arr = new int [n];

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int key;
	cin >> key;

	cout << last_index(arr, n, key);

	return 0;
}