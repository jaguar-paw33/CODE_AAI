// Inversions - A[i] & A[j] in an array are said to be an Inversion if A[i]>A[j] && i<j.


#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll merge_sorted(ll * arr, int si, int mid, int ei) {

	ll temp[ei - si + 1];

	int i, j, k = 0;

	ll count = 0;

	for (i = si, j = mid + 1; i <= mid && j <= ei;) {
		if (arr[i] > arr[j]) {
			count += (mid - i + 1);
			temp[k++] = arr[j++];
		} else {
			temp[k++] = arr[i++];
		}
	}

	while (i <= mid) {
		temp[k++] = arr[i++];
	}

	while (j <= ei) {
		temp[k++] = arr[j++];
	}

	for (int i = 0; i < (ei - si + 1); i++) {
		arr[si + i] = temp[i];
	}

	return count;
}

ll num_inversions(ll * arr, int si, int ei) {
	if (si >= ei)
		return 0;

	int mid = si + (ei - si) / 2;

	ll left_inversions = num_inversions(arr, si, mid);
	ll right_inversions = num_inversions(arr, mid + 1, ei);
	ll count = left_inversions + right_inversions + merge_sorted(arr, si, mid, ei);

	return count;
}

ll getInversions(ll *arr, int n) {
	return num_inversions(arr, 0, n - 1);
}

int main() {
	int n;
	cin >> n;

	ll * arr = new ll [n];

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	cout << getInversions(arr, n) << endl;

	delete [] arr;

	return 0;
}