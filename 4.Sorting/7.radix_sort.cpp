

// Radix Sort uses Counting Sort Digit wise to sort the given numbers

// Time Complexity - O(d*(n+k)) and since k=10 (0 to 9) and hence we get final time complexity as O(nd).

// Space Complexity - O(n+k) or O(n)

// Works only for non-negative numbers but can be made to work with negative numbers using some manipulation.

#include<iostream>
#include<climits>
#include<cstring>
using namespace std;

int find_max(int * arr, int n) {
	int max_num = INT_MIN;

	for (int i = 0; i < n; i++) {
		if (max_num < arr[i])
			max_num = arr[i];
	}

	return max_num;
}

void counting_sort(int * arr, int n, int place) {

	int output[n];

	int aux[10];

	memset(aux, 0, sizeof(int) * 10);

	for (int i = 0; i < n; i++) {
		int index = arr[i] / place;
		aux[index % 10]++ ;
	}

	for (int i = 1; i < 10; i++) {
		aux[i] += aux[i - 1];
	}

	for (int i = n - 1; i >= 0; i--) {
		int index = arr[i] / place;
		output[aux[index % 10] - 1] = arr[i];
		aux[index % 10]-- ;
	}

	for (int i = 0; i < n; i++) {
		arr[i] = output[i];
	}

}

void radix_sort(int * arr, int n, int max_num) {

	int place = 1;

	while (max_num / place) {

		counting_sort(arr, n, place);
		place *= 10;

	}

}



int main() {

	int n;
	cin >> n;

	int * arr = new int [n];

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int max_num = find_max(arr, n);

	radix_sort(arr, n, max_num);

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

	delete [] arr;

	return 0;
}