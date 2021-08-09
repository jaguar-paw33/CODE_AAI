/*

Given a non-empty array containing only positive integers, find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.



Note:




Each of the array element will not exceed 100.

The array size will not exceed 200.



Example 1:

Input: [1, 5, 11, 5]

Output: true

Explanation: The array can be partitioned as [1, 5, 5] and [11].

Example 2:

Input: [1, 2, 3, 5]

Output: false

Explanation: The array cannot be partitioned into equal sum subsets.

Level : Medium

Problem Practice Link: https://leetcode.com/problems/partition-equal-subset-sum/

Python Executable code: https://onlinegdb.com/SJdZQ73bI


Similar Problems:

Partition to K Equal Sum Subsets: https://leetcode.com/problems/partition-to-k-equal-sum-subsets/

*/

#include<bits/stdc++.h>
using namespace std;

bool helper(vector<int>&nums, int si, int & s1, int & s2) {

	if (si == nums.size()) {
		if (s1 == s2)
			return true;
		return false;
	}

	int a = s1 + nums[si];
	int b = s2 + nums[si];

	return (helper(nums, si + 1, a, s2) || helper(nums, si + 1, s1, b));
}

bool canPartition(vector<int>& nums) {

	int max_sum = 0;

	for (int i = 0; i < nums.size(); i++) {
		max_sum += nums[i];
	}

	int ** dp = new int [max_sum + 1];
	for (int i = 0; i < max_sum + 1; i++) {
		dp[i] = new int [max_sum + 1];
		for (int j = 0; j < max_sum + 1; j++) {
			dp[i][j] = -1;
		}
	}

	int s1 = 0, s2 = 0;
	return helper(nums, 0, s1, s2);
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

	cout << canPartition(nums) << endl;

	return 0;
}