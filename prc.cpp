#include<bits/stdc++.h>
using namespace std;

int partition(int * arr, int si, int ei) {
	int pivot = arr[si];
	int i, j;
	for (i = si + 1, j = si + 1; i <= ei; i++) {
		if (arr[i] <= pivot) {
			int temp = arr[i];
			arr[i] = arr[j];
			arr[j++] = temp;
		}
	}
	arr[si] = arr[j - 1];
	arr[j - 1] = pivot;
	return j - 1;
}

void quick_sort(int * arr, int si, int ei) {

	if (si >= ei)
		return;

	int pivot_index = partition(arr, si, ei);
	quick_sort(arr, si, pivot_index - 1);
	quick_sort(arr, pivot_index + 1, ei);
}

int main() {

	int n;
	cin >> n;

	int * arr = new int [n];

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	quick_sort(arr, 0, n - 1);

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

	delete [] arr;

	return 0;
}