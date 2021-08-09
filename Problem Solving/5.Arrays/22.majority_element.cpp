/*

Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.

Example 1:

Input: [3,2,3]

Output: 3

Example 2:

Input: [2,2,1,1,1,2,2]

Output: 2

Level: Easy

Problem Practice Link: https://leetcode.com/problems/majority-element/

Companies Asked in: Amazon, Microsoft, Visa

Python Executable code: https://onlinegdb.com/r1Jn6wtbL

Similar Problems:

1. Majority Element II: https://leetcode.com/problems/majority-element-ii/

2. Check if a number is majority  Element in a sorted array: https://leetcode.com/problems/check-if-a-number-is-majority-element-in-a-sorted-array/

*/

// Boyer Moore Algorithm Time - O(n) and Space - O(1)


#include<bits/stdc++.h>
using namespace std;

int majority_element(vector<int> & nums) {
	int num;
	int count = 0;

	for (int i = 0; i < nums.size(); i++) {
		if (!count) {
			num = nums[i];
			count++;
		}
		else if (num == nums[i]) {
			count++;
		} else {
			count--;
		}
	}

	count = 0;

	for (int i = 0; i < nums.size(); i++) {
		if (num == nums[i])
			count++;
	}

	if (count > (nums.size() / 2))
		return num;

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

	// -1 signifies that the number does not exist
	cout << majority_element(nums) << endl;

	return 0;
}
