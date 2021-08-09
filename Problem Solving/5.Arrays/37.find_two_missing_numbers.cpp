/*

Given an array of size n consisting integers from 1 to m has two missing values. Find those.

*/

#include<bits/stdc++.h>
using namespace std;

// Sum Approach but may cause overflow when we have very large numbers
vector<int> find_missing_two1(vector<int> & nums, int m) {
	int raw_sum = m * (m + 1) / 2;

	int sum = 0;
	for (int i = 0; i < nums.size(); i++) {
		sum += nums[i];
	}

	int rem_sum_avg = (raw_sum - sum) / 2; // One number will be less than average remaining sum and the other number will be larger, both can't be equal since each number is unique.

	int sum_to_avg = 0;

	for (int i = 1; i <= rem_sum_avg; i++) { // Compute the sum from 1 to avg
		sum_to_avg += i;
	}

	int sum_less_avg = 0;

	for (int i = 0; i < nums.size(); i++) { // Compute the sum of values <= avg
		if (nums[i] <= rem_sum_avg) {
			sum_less_avg += nums[i];
		}
	}

	int first = sum_to_avg - sum_less_avg;

	vector<int> ans;
	ans.push_back(first);
	ans.push_back(raw_sum - sum - first);

	return ans;
}


int first_set_bit_index(int n) {
	int set_bit_num = n & (~(n - 1));
	return log2(set_bit_num); // Add 1 while considering the right most bit as index 1
}

int is_ith_bit_set(int n, int i) {
	return n & (1 << i);
}

//XOR Approach
vector<int> find_missing_two2(vector<int> & nums, int m) {

	int raw_xor = 0;

	for (int i = 1; i <= m; i++) {
		raw_xor ^= i;
	}

	for (int i = 0; i < nums.size(); i++) {
		raw_xor ^= nums[i];
	}

	int first_set_bit = first_set_bit_index(raw_xor);

	int first = 0;

	for (int i = 0; i < nums.size(); i++) {
		if (is_ith_bit_set(nums[i], first_set_bit)) {
			first ^= nums[i];
		}
	}

	for (int i = 1; i <= m; i++) {
		if (is_ith_bit_set(i, first_set_bit)) {
			first ^= i;
		}
	}

	vector<int> ans;
	ans.push_back(first);
	ans.push_back(raw_xor ^ first);
	return ans;
}


int main() {
	int n, m;
	cin >> n >> m;

	vector<int> nums;
	int v;

	while (n--) {
		cin >> v;
		nums.push_back(v);
	}

	vector<int> ans1 = find_missing_two1(nums, m);
	vector<int> ans2 = find_missing_two2(nums, m);


	for (int i = 0; i < ans1.size(); i++) {
		cout << ans1[i] << " ";
	}

	cout << endl;

	for (int i = 0; i < ans2.size(); i++) {
		cout << ans2[i] << " ";
	}

	return 0;
}