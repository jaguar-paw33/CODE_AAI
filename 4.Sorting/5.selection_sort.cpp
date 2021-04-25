

// Time Complexity - O(n^2)
// Space Complexity - O(1)


#include<iostream>
#include<climits>
using namespace std;

void swap(int * arr, int i, int min_index) {
	int temp = arr[i];
	arr[i] = arr[min_index];
	arr[min_index] = temp;
}

void selection_sort(int * arr, int n) {

	for (int i = 0; i < n; i++) {
		int min_index = i;
		for (int j = i + 1; j < n; j++) {
			if (arr[min_index] > arr[j])
				min_index = j;
		}

		if (min_index != i)
			swap(arr, i, min_index);
	}
}


int main() {

	int n;
	cin >> n;

	int * arr = new int [n];

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	selection_sort(arr, n);

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

	delete [] arr;

	return 0;

}