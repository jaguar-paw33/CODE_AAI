
// Merge Sort - Divide and Conquer strategy based algorithm

// Time Complexity - O(nlogn)
// Space Complexity - O(n)

#include<iostream>
using namespace std;

void merge_sort(int * arr, int si, int ei) {

	if (si >= ei)
		return;

	int mid = (si + ei) / 2;

	merge_sort(arr, si, mid);
	merge_sort(arr, mid + 1, ei);


	int temp[ei - si + 1];

	int i, j, k = 0;

	for (i = si, j = mid + 1; i <= mid && j <= ei;) {
		if (arr[i] < arr[j]) {
			temp[k++] = arr[i++];
		} else {
			temp[k++] = arr[j++];
		}
	}

	while (i <= mid) {
		temp[k++] = arr[i++];
	}

	while (j <= ei) {
		temp[k++] = arr[j++];
	}

	for (int i = si; i <= ei; i++) {
		arr[i] = temp[i - si];
	}

	return;
}


int main() {
	int n;
	cin >> n;

	int * arr = new int [n];

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	merge_sort(arr, 0, n - 1);

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

	delete [] arr;

	return 0;
}