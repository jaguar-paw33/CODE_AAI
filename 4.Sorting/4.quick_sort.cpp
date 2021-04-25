

// Time Complexity - O(nlogn) in best case (when the pivot element gets the middle position in the array) and average case
//							the recurrence equation will be T(n) = 2T(n/2) + cn.

//					 O(n^2) in the worst case when the array is already sorted (ascending or descending) and the pivot is chosen as the first element,
// 							the recurrence equation will be T(n) = T(0) +T(n-1) + cn, when the array is sorted in ascending order.

//					To make the worst case time complexity of Quick Sort to be O(nlogn) we make use of Randomization where we randomply
//					pick an element from the array and swap it with the first element of the array and the consider the first element as pivot.

// 					But this is possible only when we have distinct elements in the array because in such a case the probability of picking the smallest
//					element as pivot in each iteration will be very low, but if we have all the elements to be same in the array then the worst case time
//					complexity is O(n^2). Also, when we are considering worst case then even in the distinct element case we will assume that the pivot is
//					always chosen as the smallest element even though it has a very less probability and hence in the worst case Quick Sort as well as
//					Randomized Quick Sort takes O(n^2) time.

// Space Complexity - O(1)

#include<iostream>
using namespace std;

int partition(int * arr, int si, int ei) {

	/*
		Algo -

		1. pivot = arr[si]
		2. i = si,j=si+1
		3. Traverse the whole array:
			if(arr[j]>=pivot)
				increment j
			else
				increment i
				swap arr[i] with arr[j]
		4. swap arr[i] with pivot
		5. return i (pivot index)
	*/

	int pivot = arr[si];
	int i = si, j = si + 1;

	while (j <= ei) {
		if (arr[j] <= pivot) {
			i++;
			int temp = arr[j];
			arr[j] = arr[i];
			arr[i] = temp;
		}
		j++;
	}

	arr[si] = arr[i];
	arr[i] = pivot;

	return i;
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