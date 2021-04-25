/*

Given an array A of size n and an integer K, return all subsets of A which sum to K.
Subsets are of length varying from 0 to n, that contain elements of the array. But the order of elements should remain same as in the input array.

Note : The order of subsets are not important.

Input format :

Line 1 : Integer n, Size of input array
Line 2 : Array elements separated by space
Line 3 : K

Constraints :
1 <= n <= 20

Sample Input :
9
5 12 3 17 1 18 15 3 17
6
Sample Output :
3 3
5 1

*/

#include<bits/stdc++.h>
using namespace std;

int return_subset_sum_k(int * arr, int n, int k, int output[][30]) {

	if (n == 0) {
		if (!k) {
			output[0][0] = 0;
			return 1;
		} else {
			return 0;
		}
	}

	int output1[int(pow(2, n))][30];
	int output2[int(pow(2, n))][30];

	int size1 = return_subset_sum_k(arr + 1, n - 1, k, output1);
	int size2 = return_subset_sum_k(arr + 1, n - 1, k - arr[0], output2);

	for (int i = 0; i < size1; i++) {
		output[i][0] = output1[i][0];
		for (int j = 1; j <= output1[i][0]; j++) {
			output[i][j] = output1[i][j];
		}
	}

	for (int i = 0; i < size2; i++) {
		output[i + size1][0] = output2[i][0] + 1;
		for (int j = 1; j <= output2[i][0]; j++) {
			output[i + size1][j + 1] = output2[i][j];
		}
		output[i + size1][1] = arr[0];
	}

	return size1 + size2;
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

	int output[int(pow(2, n))][30];


	int size = return_subset_sum_k(arr, n, k, output);

	for (int i = 0; i < size; i++) {
		for (int j = 1; j <= output[i][0]; j++) {
			cout << output[i][j] << " ";
		}
		cout << endl;
	}

	delete [] arr;

	return 0;
}