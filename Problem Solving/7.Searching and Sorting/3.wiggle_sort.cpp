/*

Given an unsorted array nums, reorder it in-place such that nums[0] <= nums[1] >= nums[2] <= nums[3]....

Example:

Input: nums = [3,5,2,1,6,4]

Output: One possible answer is [3,5,1,6,2,4]

Level: Medium

Problem Practice Link: https://leetcode.com/problems/wiggle-sort/ or https://www.interviewbit.com/problems/wave-array/

*/

#include<bits/stdc++.h>
using namespace std;

// Time Complexity - O(nlogn) Space Complexity - O(1), produces lexicographical sorted output
void wiggle_sort1 (vector<int> &nums) {
	sort(nums.begin(), nums.end());
	for (int i = 0; i < nums.size() - 1; i += 2) {
		int temp = nums[i];
		nums[i] = nums[i + 1];
		nums[i + 1] = temp;
	}
}


//Time Complexity - O(n) Space Complexity - O(1) but does not produce lexicographic sorted output
void wiggle_sort2(vector<int> & nums) {
	// all odd index numbers must be greater than or equal to the even index numbers.
	for (int i = 1; i < nums.size(); i += 2) {
		if (nums[i - 1] > nums[i]) {
			int temp = nums[i - 1];
			nums[i - 1] = nums[i];
			nums[i] = temp;
		}

		if (i + 1 < nums.size() && nums[i] < nums[i + 1]) {
			int temp = nums[i];
			nums[i] = nums[i + 1];
			nums[i + 1] = temp;
		}
	}
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

	wiggle_sort2(nums);

	for (auto v : nums) {
		cout << v << " ";
	}

	return 0;
}