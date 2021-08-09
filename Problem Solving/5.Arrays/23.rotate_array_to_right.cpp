/*

Given an array, rotate the array to the right by k steps, where k is non-negative.

Example 1:

Input: [1,2,3,4,5,6,7] and k = 3

Output: [5,6,7,1,2,3,4]

Explanation:

rotate 1 steps to the right: [7,1,2,3,4,5,6]

rotate 2 steps to the right: [6,7,1,2,3,4,5]

rotate 3 steps to the right: [5,6,7,1,2,3,4]

Example 2:

Input: [-1,-100,3,99] and k = 2

Output: [3,99,-1,-100]

Explanation:

rotate 1 steps to the right: [99,-1,-100,3]

rotate 2 steps to the right: [3,99,-1,-100]

Note:

Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.

Could you do it in-place with O(1) extra space? Level: Easy

Problem Practice Link: https://leetcode.com/problems/rotate-array/

Companies Asked in: Amazon, Microsoft, Paypal, Goldman sachs, Facebook, Uber, Cisco, Adobe

Python Executable code: https://onlinegdb.com/SkldEGH2ZI

Similar Problems:

1. Rotate List: https://leetcode.com/problems/rotate-list/

2. Reverse Words in a String II: https://leetcode.com/problems/reverse-words-in-a-string-ii/

*/


#include<bits/stdc++.h>
using namespace std;

void reverse_array(vector<int> & nums, int si, int ei) {
	for (int i = si, j = ei; i < j; i++, j--) {
		int temp = nums[i];
		nums[i] = nums[j];
		nums[j] = temp;
	}
}

void rotate_right(vector<int> & nums, int rotate_factor) {

	rotate_factor = rotate_factor % nums.size(); // If rotate_factor > n

	reverse_array(nums, 0, nums.size() - 1);
	reverse_array(nums, 0, rotate_factor - 1);
	reverse_array(nums, rotate_factor, nums.size() - 1);
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

	int rotate_factor;
	cin >> rotate_factor;

	rotate_right(nums, rotate_factor);

	for (int i = 0; i < nums.size(); i++) {
		cout << nums[i] << " ";
	}

	return 0;
}