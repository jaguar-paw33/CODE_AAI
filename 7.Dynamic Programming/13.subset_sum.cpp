#include<bits/stdc++.h>
using namespace std;

bool subset_sum_rec(int * arr, int n, int sum) {
	if (sum == 0)
		return true;
	else if (!n)
		return false;

	return subset_sum_rec(arr + 1, n - 1, sum - arr[0]) || subset_sum_rec(arr + 1, n - 1, sum);
}

bool subset_sum_mem(int * arr, int n, int sum) {

}

int main() {
	int n;
	cin >> n;

	int * arr = new int [n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int sum;
	cin >> sum;

	cout << subset_sum_rec(arr, n, sum) << endl;

	int ** mem = new int * [n + 1];

	for (int i = 0; i < n + 1; i++) {
		mem[i] = new int [sum + 1];
		for (int j = 0; j < sum + 1; j++) {
			if (n == 0 || sum == 0) {
				mem[]
			}
		}
	}


	return 0;
}

