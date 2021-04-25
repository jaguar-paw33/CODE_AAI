/*

Given an integer sorted array (sorted in increasing order) and an element x, find the x in given array using binary search. Return the index of x.
Return -1 if x is not present in the given array.

Note : If given array size is even, take first mid.

Input format :

Line 1 : Array size

Line 2 : Array elements (separated by space)

Line 3 : x (element to be searched)

Sample Input :
6
2 3 4 5 6 8
5
Sample Output:
3

*/

#include<bits/stdc++.h>
using namespace std;

int binary_search(int * arr, int si, int ei, int key) {
	if (si > ei)
		return -1;
	int mid = si + ((ei - si) / 2);

	if (arr[mid] == key)
		return mid;
	else if (arr[mid] < key)
		return binary_search(arr, mid + 1, ei, key);
	else
		return binary_search(arr, si, mid - 1, key);

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

	cout << binary_search(arr, 0, n - 1, key) << endl;

	delete [] arr;

	return 0;
}