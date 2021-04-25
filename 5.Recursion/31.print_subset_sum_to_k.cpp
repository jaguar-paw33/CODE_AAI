/*

Given an array A and an integer K, print all subsets of A which sum to K.
Subsets are of length varying from 0 to n, that contain elements of the array. But the order of elements should remain same as in the input array.
Note : The order of subsets are not important. Just print them in different lines.
Input format :
Line 1 : Size of input array
Line 2 : Array elements separated by space
Line 3 : K
Sample Input:
9
5 12 3 17 1 18 15 3 17
6
Sample Output:
3 3
5 1

*/

#include<bits/stdc++.h>
using namespace std;

void print_subset_sum_k(int * arr, int n, int k, int * output, int size) {
	if (n == 0) {
		if (!k) {
			for (int i = 0; i < size; i++) {
				cout << output[i] << " ";
			}
			cout << endl;
		}
		return;
	}

	print_subset_sum_k(arr + 1, n - 1, k, output, size);
	output[size] = arr[0];
	print_subset_sum_k(arr + 1, n - 1, k - arr[0], output, size + 1 );
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

	int output[n];

	print_subset_sum_k(arr, n, k, output, 0);

	return 0;
}