/*

Given an integer array (of length n), find and print all the subsets of input array.
Subsets are of length varying from 0 to n, that contain elements of the array. But the order of elements should remain same as in the input array.

Note : The order of subsets are not important. Just print the subsets in different lines.

Input format :
Line 1 : Integer n, Size of array
Line 2 : Array elements (separated by space)

Constraints :
1 <= n <= 15

Sample Input:
3
15 20 12
Sample Output:
[] (this just represents an empty array, don't worry about the square brackets)
12
20
20 12
15
15 12
15 20
15 20 12

*/

#include<bits/stdc++.h>
using namespace std;

void print_subsets(int * arr, int n, int * output, int size) {
	if (n == 0) {
		for (int i = 0; i < size; i++) {
			cout << output[i] << " ";
		}
		cout << endl;
		return;
	}

	print_subsets(arr + 1, n - 1, output, size);

	output[size] = arr[0];

	print_subsets(arr + 1, n - 1, output, size + 1);
}

int main() {
	int n;
	cin >> n;

	int * arr = new int [n];

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int * output = new int [n];

	print_subsets(arr, n, output, 0);

	delete [] arr;
	delete [] output;

	return 0;
}