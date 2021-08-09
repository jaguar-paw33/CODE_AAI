/*

Problem Statement:

Given two arrays of integers nums and index. Your task is to create target array under the following rules:

Initially target array is empty.

From left to right read nums[i] and index[i], insert at index index[i] the value nums[i] in target array.

Repeat the previous step until there are no elements to read in nums and index.



Return the target array.

It is guaranteed that the insertion operations will be valid.

Example 1:

Input: nums = [0,1,2,3,4], index = [0,1,2,2,1]

Output: [0,4,1,3,2]

Explanation: nums index target 0 0 [0] 1 1 [0,1] 2 2 [0,1,2] 3 2 [0,1,3,2] 4 1 [0,4,1,3,2]

Example 2:

Input: nums = [1,2,3,4,0], index = [0,1,2,3,0]

Output: [0,1,2,3,4]

Explanation: nums index target 1 0 [1] 2 1 [1,2] 3 2 [1,2,3] 4 3 [1,2,3,4] 0 0 [0,1,2,3,4]

Example 3:

Input: nums = [1], index = [0]

Output: [1]

Constraints:




1 <= nums.length, index.length <= 100

nums.length == index.length

0 <= nums[i] <= 100

0 <= index[i] <= i


Level : Easy

Problem Practice Link: https://leetcode.com/problems/create-target-array-in-the-given-order/

*/

#include<bits/stdc++.h>
using namespace std;

vector<int> create_in_order(vector<int> & nums, vector<int> & index) {
	vector<int> ans;

	for (int i = 0; i < index.size(); i++) {
		ans.push_back(-1);
	}
	int size = 0;

	ans[index[0]] = nums[0];
	size++;
	for (int i = 1; i < index.size(); i++) {
		if (ans[index[i]] != -1) {
			for (int j = size - 1; j >= index[i]; j--) {
				ans[j + 1] = ans[j];
			}
		}
		ans[index[i]] = nums[i];
		size++;
	}
	return ans;
}

int main() {
	int n;
	cin >> n;

	vector<int> index;
	vector<int> nums;

	while (n--) {
		int i, v;
		cin >> v >> i;
		nums.push_back(v);
		index.push_back(i);
	}

	vector<int> ans = create_in_order(nums, index);

	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}

	return 0;
}