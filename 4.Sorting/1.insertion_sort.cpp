
// Time Complexity - O(n) best case
//					 O(n^2) worst case
// Space Complexity - O(1)

#include<iostream>
using namespace std;

void insertion_sort(int * arr, int n) {
	for (int i = 1; i < n; i++) {
		int temp = arr[i];
		int j;
		for (j = i - 1; j >= 0 && arr[j] > temp; j--) {
			arr[j + 1] = arr[j];
		}
		arr[j + 1] = temp;
	}
}

int main() {
	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	insertion_sort(arr, n);
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	return 0;
}