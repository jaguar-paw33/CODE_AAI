/*

Given an integer array of size N. Sort this array (in decreasing order) using heap sort.

Note: Space complexity should be O(1).

Input Format:
The first line of input contains an integer, that denotes the value of the size of the array or N.
The following line contains N space separated integers, that denote the value of the elements of the array.

Output Format :
The first and only line of output contains array elements after sorting. The elements of the array in the output are separated by single space.

Constraints :
1 <= n <= 10^6
Time Limit: 1 sec

Sample Input 1:
6
2 6 8 5 4 3
Sample Output 1:
8 6 5 4 3 2

*/


#include<bits/stdc++.h>
using namespace std;

void upheapify(int * arr, int ei) {
	int childIndex = ei;
	while (childIndex > 0) {
		int parentIndex = (childIndex - 1) / 2;
		if (arr[parentIndex] > arr[childIndex])
		{
			int temp = arr[parentIndex];
			arr[parentIndex] = arr[childIndex];
			arr[childIndex] = temp;
		} else {
			break;
		}
		childIndex = parentIndex;
	}
}

void downHeapify(int * arr, int ei) {
	int parentIndex = 0;
	int lchildIndex = 2 * parentIndex + 1;
	int rchildIndex = 2 * parentIndex + 2;
	while (lchildIndex <= ei) {
		int tempIndex = parentIndex;
		if (arr[tempIndex] > arr[lchildIndex])
			tempIndex = lchildIndex;
		if (rchildIndex <= ei && arr[tempIndex] > arr[rchildIndex])
			tempIndex = rchildIndex;
		if (tempIndex == parentIndex)
			break;
		int temp = arr[tempIndex];
		arr[tempIndex] = arr[parentIndex];
		arr[parentIndex] = temp;
		parentIndex = tempIndex;
		lchildIndex = 2 * parentIndex + 1;
		rchildIndex = 2 * parentIndex + 2;
	}
}

void heap_sort(int * arr, int n) {
	for (int i = 1; i < n; i++) {
		upheapify(arr, i);
	}
	for (int i = n - 1; i > 0; i--) {
		int temp = arr[i];
		arr[i] = arr[0];
		arr[0] = temp;
		downHeapify(arr, i - 1);
	}
}

int main() {
	int n;
	cin >> n;

	int* arr = new int [n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	heap_sort(arr, n);
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	delete [] arr;
	return 0;
}
