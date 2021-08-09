/*

You are given an integer array/list(ARR) of size N. It contains only 0s, 1s and 2s. Write a solution to sort this array/list in a 'single scan'.
'Single Scan' refers to iterating over the array/list just once or to put it in other words, you will be visiting each element in the array/list just once.
Note:
You need to change in the given array/list itself. Hence, no need to return or print anything.
Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

First line of each test case or query contains an integer 'N' representing the size of the array/list.

Second line contains 'N' single space separated integers(all 0s, 1s and 2s) representing the elements in the array/list.
Output Format :
For each test case, print the sorted array/list elements in a row separated by a single space.

Output for every test case will be printed in a separate line.
Constraints :
1 <= t <= 10^2
0 <= N <= 10^5
Time Limit: 1 sec
Sample Input 1:
1
7
0 1 2 0 2 0 1
Sample Output 1:
0 0 0 1 1 2 2
Sample Input 2:
2
5
2 2 0 1 1
7
0 1 2 0 1 2 0
Sample Output 2:
0 1 1 2 2
0 0 0 1 1 2 2

*/

#include<bits/stdc++.h>
using namespace std;

// Two parse
void sort_012(int * arr, int n) {
	int i, j, k;
	int * temp = new int [n];
	for (i = 0, j = 0, k = n - 1; i < n; i++) {
		if (!arr[i])
			temp[j++] = 0;
		else if (arr[i] == 2)
			temp[k--] = 2;
	}

	for (int i = j; i <= k; i++) {
		temp[i] = 1;
	}

	for (int i = 0; i < n; i++) {
		arr[i] = temp[i];
	}

	delete [] temp;
}

// Single Parse
void sort_012_single_parse(int * arr, int n) {

	int low = 0;
	int cur = 0;
	int high = n - 1;

	while (cur <= high) {
		if (arr[cur] == 2) {
			arr[cur] = arr[high];
			arr[high--] = 2;
		} else if (arr[cur] == 0) {
			arr[cur++] = arr[low];
			arr[low++] = 0;
		} else {
			cur++;
		}
	}

}

int main() {

	int n;
	cin >> n;

	int * arr = new int [n];

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort_012_single_parse(arr, n);

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

	delete [] arr;

	return 0;

}