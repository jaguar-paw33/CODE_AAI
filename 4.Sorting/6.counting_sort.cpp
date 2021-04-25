

// Constraint - Numbers should be non-negative(o to k) (can be also used with negative numbers with slight modification)

// Time Complexity - O(n+k)

// Space Complexity O(n+k)

// Counting Sort is a Stable Sorting Algorithm

#include<iostream>
#include<climits>
#include<cstring>
using namespace std;

void counting_sort(int * arr, int n, int k) {
	int output[n];

	int aux[k + 1];

	memset(aux, 0, sizeof(int) * (k + 1));

	for (int i = 0; i < n; i++) {
		aux[arr[i]]++;
	}

	for (int i = 1; i < k + 1; i++) {
		aux[i] += aux[i - 1];
	}


	for (int i = n - 1; i >= 0; i--) {
		output[aux[arr[i]] - 1] = arr[i];
		aux[arr[i]]--;
	}

	for (int i = 0; i < n; i++) {
		arr[i] = output[i];
	}
}


int main() {
	int n;
	cin >> n;


	int * arr = new int [n];
	int k = INT_MIN;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		while (arr[i] < 0) {
			cout << "Enter Non-Negative Number" << endl;
			cin >> arr[i];
		}
		if (k < arr[i])
			k = arr[i];
	}

	counting_sort(arr, n, k);

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

	delete [] arr;

	return 0;
}