/*


Given an unsorted integer array, find the smallest missing positive integer.



Example 1:





Input: [1,2,0]

Output: 3



Example 2:





Input: [3,4,-1,1]

Output: 2



Example 3:





Input: [7,8,9,11,12]

Output: 1



Note:



Your algorithm should run in O(n) time and uses constant extra space.



Level: Hard

Problem Practice Link: https://leetcode.com/problems/first-missing-positive/



Similar Problems:

1. Missing Number: https://leetcode.com/problems/missing-number/

2. Find Duplicate Number: https://leetcode.com/problems/find-the-duplicate-number/

3. Find All Numbers disappeared in an array: https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/

*/

#include<bits/stdc++.h>
using namespace std;



// Cna be simply done in O(nlogn) by sorting but the below approach uses O(n)
int firstMissingPositive(vector<int> &  nums) {
	int minPos = INT_MAX, maxPos = INT_MIN;
	for (auto v : nums) {
		if (v > 0) {
			if (v < minPos) {
				minPos = v;
			}
			if (v > maxPos) {
				maxPos = v;
			}
		}
	}

	if (minPos != 1)
		return 1;

	if (minPos == maxPos) // for a case where all +ve values are 1
		return 2;

	// We will modify the array so as to have all the values between 0 and n-1
	// where n is the size of the array. Since, the first missing positive will either
	// lie between 2 and n-1 or will be n if we have a consecutive sorted array starting from 1
	// hence we can modify all the negative, 0 and greater than n-1 elements in the array.
	for (int i = 0; i < nums.size(); i++) {
		if (nums[i] <= 0 || nums[i] > nums.size() - 1) {
			nums[i] = 1; // Making all these 1 since 1 is already present
		}
	}

	for (int i = 0; i < nums.size(); i++) {
		if (nums[abs(nums[i])] > 0) {
			nums[abs(nums[i])] *= -1;
		}
	}

	for (int i = 1; i < nums.size(); i++) {
		if (nums[i] > 0) {
			return abs(i);
		}
	}

	if (maxPos == nums.size())
		return maxPos + 1;
	else
		return nums.size();
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

	cout << firstMissingPositive(nums) << endl;

	return 0;
}
