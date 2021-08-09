/*

Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.

Your algorithm's runtime complexity must be in the order of O(log n).
Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0

Output: 4

Example 2:

Input: nums = [4,5,6,7,0,1,2], target = 3

Output: -1

Level: Medium

Problem Practice link: https://leetcode.com/problems/search-in-rotated-sorted-array/

Python Code Executable Code:  https://onlinegdb.com/BkoThLYWI


Similar Problem:

1. Search in sorted rotated Array II: https://leetcode.com/problems/search-in-rotated-sorted-array-ii/

2. Find Minimum in rotated sorted array: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/


*/

#include<bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> & nums, int si, int ei, int target) {
	while (si <= ei) {
		int mid = si + (ei - si) / 2;

		if (nums[mid] == target) {
			return mid;
		} else if (nums[mid] > target) {
			ei = mid - 1;
		} else {
			si = mid + 1;
		}
	}
	return -1;
}


int find_target(vector<int> & nums, int si, int ei, int target) {

	if (si > ei)
		return -1;

	int mid = si + (ei - si) / 2;

	if (nums[mid] == target) {
		return mid;
	} else if (nums[mid] >= nums[si]) {
		if (target < nums[mid] && target >= nums[si])
			return binarySearch(nums, si, mid - 1, target);
		else
			return find_target(nums, mid + 1, ei, target);
	} else if (nums[mid] <= nums[ei]) {
		if (target > nums[mid] && target <= nums[ei])
			return binarySearch(nums, mid + 1, ei, target);
		else
			return find_target(nums, si, mid - 1, target);
	} else
		return -1;
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

	int target;
	cin >> target;

	cout << find_target(nums, 0 , nums.size() - 1, target) << endl;

	return 0;
}
