#include<bits/stdc++.h>
using namespace std;

void k_sorted(int * arr, int n, int k) {
	priority_queue<int> pq;
	for (int i = 0; i < k; i++) {
		pq.push(arr[i]);
	}
	int j = 0;
	for (int i = k; i < n; i++) {
		arr[j++] = pq.top();
		pq.pop();
		pq.push(arr[i]);
	}
	while (!pq.empty()) {
		arr[j++] = pq.top();
		pq.pop();
	}
}

int main() {
	int n;
	cin >> n;
	int * arr = new int [n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int k;
	cin >> k;
	k_sorted(arr, n, k);
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	delete [] arr;
	return 0;
}