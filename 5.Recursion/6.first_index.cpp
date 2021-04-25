/*

Given an array of length N and an integer x, you need to find and return the first index of integer x present in the array. Return -1 if it is not present in the array.
First index means, the index of first occurrence of x in the input array.

Do this recursively. Indexing in the array starts from 0.

Input Format :
Line 1 : An Integer N i.e. size of array
Line 2 : N integers which are elements of the array, separated by spaces
Line 3 : Integer x

Output Format :
first index or -1

Constraints :
1 <= N <= 10^3

Sample Input :
4
9 8 10 8
8

Sample Output :
1

*/


#include<bits/stdc++.h>
using namespace std;

int first_index(int * arr, int n, int key) {
	if (n <= 0)
		return -1;

	if (arr[0] == key)
		return 0;

	int index = first_index(arr + 1, n - 1, key);

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

	cout << first_index(arr, n, key);

	delete [] arr;

	return 0;
}