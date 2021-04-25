
// Time Complexity - O(n^2)
// Space Complexity - O(1)


#include<iostream>
using namespace std;

void bubble_sort(int * arr, int n) {

	bool swapped = false;

	for (int i = n - 1; i >= 1; i--) {
		for (int j = 0; j < i; j++) {
			if (arr[i] < arr[j]) {
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
				swapped = true;
			}
		}

		if (!swapped)
			break;
	}
}

int main() {
	int n;
	cin >> n;

	int * arr = new int [n];

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	bubble_sort(arr, n);

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

	delete [] arr;

	return 0;
}
