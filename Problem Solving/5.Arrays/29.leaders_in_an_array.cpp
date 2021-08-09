/*

An element is leader if it is greater than all the elements to its right side. And the rightmost element is always a leader. For example int the array {16, 17, 4, 3, 5, 2}, leaders are 17, 5 and 2.

*/


#include<bits/stdc++.h>
using namespace std;

vector<int> find_leaders(vector<int> & nums) {
	vector<int> leaders;
	if (!nums.size())
		return leaders;

	leaders.push_back(nums[nums.size() - 1]);

	int max_val = leaders[0];

	for (int i = nums.size() - 2; i >= 0; i--) {
		if (max_val < nums[i]) {
			max_val = nums[i];
			leaders.push_back(nums[i]);
		}
	}

	return leaders;
}

int main() {
	int n;
	cin >> n;

	vector<int> nums;

	int v;
	while (n--) {
		cin >> v;
		nums.push_back(v);
	}

	vector<int> leaders = find_leaders(nums);

	for (int i = 0; i < leaders.size(); i++) {
		cout << leaders[i] << " ";
	}

	return 0;
}