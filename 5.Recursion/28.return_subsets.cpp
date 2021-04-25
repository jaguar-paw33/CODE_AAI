/*

Given an integer array (of length n), find and return all the subsets of input array.
Subsets are of length varying from 0 to n, that contain elements of the array. But the order of elements should remain same as in the input array.

Note : The order of subsets are not important.

Input format :

Line 1 : Size of array

Line 2 : Array elements (separated by space)

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

int return_subsets(int * arr, int n, int ** output) {
	if (n <= 0)
	{
		output[0][0] = 0;
		return 1;
	}

	int rows = return_subsets(arr + 1, n - 1, output);

	for (int i = 0; i < rows; i++) {
		int cols = output[i][0];
		for (int j = 1; j <= cols; j++) {
			output[i + rows][j + 1] = output[i][j];
		}
		output[i + rows][1] = arr[0];
		output[i + rows][0] = output[i][0] + 1;
	}

	return 2 * rows;
}

int main() {
	int n;
	cin >> n;

	int * arr = new int [n];

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int ** output = new int * [int(pow(2, n))];
	for (int i = 0; i < int(pow(2, n)); i++) {
		output[i] = new int [n];
	}

	int rows = return_subsets(arr, n, output);

	for (int i = 0; i < rows; i++) {
		for (int j = 1; j <= output[i][0]; j++) {
			cout << output[i][j] << " ";
		}
		cout << endl;
	}

	for (int i = 0; i < int(pow(2, n)); i++) {
		delete [] output[i];
	}

	delete [] output;

	delete [] arr;

	return 0;
}