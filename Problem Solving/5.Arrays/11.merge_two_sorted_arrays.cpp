/*

You have been given two sorted arrays/lists(ARR1 and ARR2) of size N and M respectively, merge them into a third array/list such that the third array is also sorted.
Input Format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

First line of each test case or query contains an integer 'N' representing the size of the first array/list.

Second line contains 'N' single space separated integers representing the elements of the first array/list.

Third line contains an integer 'M' representing the size of the second array/list.

Fourth line contains 'M' single space separated integers representing the elements of the second array/list.
Output Format :
For each test case, print the sorted array/list(of size N + M) in a single row, separated by a single space.

Output for every test case will be printed in a separate line.
Constraints :
1 <= t <= 10^2
0 <= N <= 10^5
0 <= M <= 10^5
Time Limit: 1 sec
Sample Input 1 :
1
5
1 3 4 7 11
4
2 4 6 13
Sample Output 1 :
1 2 3 4 4 6 7 11 13
Sample Input 2 :
2
3
10 100 500
7
4 7 9 25 30 300 450
4
7 45 89 90
0
Sample Output 2 :
4 7 9 10 25 30 100 300 450 500
7 45 89 90

*/

#include<iostream>
using namespace std;

int * merge_sorted(int * arr1, int n1, int * arr2, int n2) {

	int * arr = new int [n1 + n2];
	int i, j, k = 0;

	for (i = 0, j = 0; i < n1 && j < n2;) {
		if (arr1[i] < arr2[j]) {
			arr[k++] = arr1[i++];
		} else {
			arr[k++] = arr2[j++];
		}
	}

	while (i < n1) {
		arr[k++] = arr1[i++];
	}

	while (j < n2) {
		arr[k++] = arr2[j++];
	}

	return arr;
}

int main() {
	int n1, n2;
	cin >> n1 >> n2;

	int * arr1 = new int [n1];

	for (int i = 0; i < n1; i++) {
		cin >> arr1[i];
	}

	int * arr2 = new int [n2];

	for (int i = 0; i < n2; i++) {
		cin >> arr2[i];
	}

	int * merged = merge_sorted(arr1, n1, arr2, n2);

	for (int i = 0; i < n1 + n2; i++) {
		cout << merged[i] << " ";
	}

	delete [] arr1;
	delete [] arr2;
	delete [] merged;

	return 0;

}