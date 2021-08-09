
/*

Given an unsorted array return whether an increasing subsequence of length 3 exists or not in the array.

Formally the function should:

Return true if there exists i, j, k

such that arr[i] < arr[j] < arr[k] given 0 ≤ i < j < k ≤ n-1 else return false.

Note: Your algorithm should run in O(n) time complexity and O(1) space complexity.

Example 1:

Input: [1,2,3,4,5]

Output: true

Example 2:

Input: [5,4,3,2,1]

Output: false

Level: Medium

Problem Practice Link: https://leetcode.com/problems/increasing-triplet-subsequence/

Python Executable code: https://onlinegdb.com/rkWYgDFZU

Similar Problems

Longest Increasing Subsequence: https://leetcode.com/problems/longest-increasing-subsequence/

*/

#include<bits/stdc++.h>
using namespace std;


// Time Complexity - O(n)
bool increasing_sorted_triplet(vector<int> & nums) {

	int min_val = INT_MAX, max_val = INT_MIN;

	for (int i = 0; i < nums.size(); i++) {
		if (min_val > nums[i]) {
			min_val = nums[i];
		} else if ((max_val == INT_MIN || nums[i] <= max_val) && nums[i] > min_val) {
			max_val = nums[i];
		} else if (nums[i] > max_val && (min_val != INT_MAX) && (max_val != INT_MIN)) {
			return true;
		}
	}
	return false;
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

	cout << increasing_sorted_triplet(nums) << endl;

	return 0;
}
