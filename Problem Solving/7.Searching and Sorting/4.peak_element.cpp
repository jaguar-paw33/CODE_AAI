/*

A peak element is an element that is greater than its neighbors.

Given an input array nums, where nums[i] ≠ nums[i+1], find a peak element and return its index.

The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.

You may imagine that nums[-1] = nums[n] = -∞.

Example 1:

Input: nums = [1,2,3,1]

Output: 2

Explanation: 3 is a peak element and your function should return the index number 2.

Example 2:

Input: nums = [1,2,1,3,5,6,4]

Output: 1 or 5

Explanation: Your function can return either index number 1 where the peak element is 2, or index number 5 where the peak element is 6.

Follow up: Your solution should be in logarithmic complexity.

Level: Medium

Problem Practice Link: https://leetcode.com/problems/find-peak-element/

Similar Questions:

Peak Index in a Mountain Array: https://leetcode.com/problems/peak-index-in-a-mountain-array/

*/

#include<bits/stdc++.h>
using namespace std;

// Time Complexity - O(n) Space Complexity - O(1)
int findPeakElement1(vector<int>& nums) {
	// Either we can finf the index of the max element or we can go to each element and
	// compare it with the left and right neighbors and return the index of the valid element

	// Max Approach
	int max = nums[0];
	int max_idx = 0;
	for (int i = 1; i < nums.size(); i++) {
		if (max < nums[i]) {
			max = nums[i];
			max_idx = i;
		}
	}
	return max_idx;
}


// Time Complexity - O(logn) Space Complexity - O(1)
int findPeakElement2(vector<int>& nums) {
	// For the existence of a peak element we must have a subarray(can be of size 1 also)
	// which is sorted till the peak element and then the subarray(can be of size 1 also) starting after the peak element must be less than the peak element
	// hence we will use Binary Search to find such a matrix

	if (nums.size() == 1)
		return 0;

	if (nums[0] > nums[1])
		return 0;
	if (nums[nums.size() - 1] > nums[nums.size() - 2])
		return nums.size() - 1;

	int si = 1;
	int ei = nums.size() - 2;

	while (si <= ei) {
		int mid = si + (ei - si) / 2;
		if (mid >= si && mid <= ei && nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1]) {
			return mid;
		} else if (mid >= si && mid <= ei && nums[mid] > nums[mid - 1] && nums[mid] < nums[mid + 1]) {
			si = mid + 1;
		} else {
			ei = mid - 1;
		}
	}

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

	cout << findPeakElement1(nums) << endl;
	cout << findPeakElement2(nums) << endl;


	return 0;
}