/*

Given an integer array, you need to find one continuous subarray that if you only sort this subarray in ascending order, then the whole array will be sorted in ascending order, too.

You need to find the shortest such subarray and output its length.

Example 1:

Input: [2, 6, 4, 8, 10, 9, 15]

Output: 5

Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.
Note:




Then length of the input array is in range [1, 10,000].

The input array may contain duplicates, so ascending order here means <=.


Level: Easy

Problem Practice link: https://leetcode.com/problems/shortest-unsorted-continuous-subarray/

Companies Asked in: Amazon, Google, Uber, Flipkart

*/

#include<bits/stdc++.h>
using namespace std;


// Time Complexity - O(nlogn) Space Complexity - O(n)
int find_subarray1(vector<int> & nums) {

	vector<int> temp;

	for (int i = 0; i < nums.size(); i++) {
		temp.push_back(nums[i]);
	}

	sort(temp.begin(), temp.end());

	int si, ei, i;

	for (i = 0; i < nums.size(); i++) {
		if (nums[i] != temp[i]) {
			si = i;
			break;
		}
	}

	if (i == nums.size())
		return 0;

	for (int i = nums.size() - 1; i >= 0; i--) {
		if (nums[i] != temp[i]) {
			ei = i;
			break;
		}
	}

	return ei - si + 1;
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

	cout << find_subarray1(nums) << endl;
	cout << find_subarray2(nums) << endl;

	return 0;
}