/*

Given an array nums of integers, return how many of them contain an even number of digits.

Example 1:


Input: nums = [12,345,2,6,7896]

Output: 2

Explanation:

12 contains 2 digits (even number of digits).

345 contains 3 digits (odd number of digits).

2 contains 1 digit (odd number of digits).

6 contains 1 digit (odd number of digits).

7896 contains 4 digits (even number of digits).

Therefore only 12 and 7896 contain an even number of digits.



Example 2:





Input: nums = [555,901,482,1771]

Output: 1

Explanation:

Only 1771 contains an even number of digits.

Constraints:



1 <= nums.length <= 500

1 <= nums[i] <= 10^5


Level: Easy

Problem Practice Link: https://leetcode.com/problems/find-numbers-with-even-number-of-digits/

*/

#include<bits/stdc++.h>
using namespace std;


bool is_even_digits(int n) {
	int count = 0;
	while (n) {
		count++;
		n /= 10;
	}
	return !(count % 2);
}

// Time Complexity - O(n*k) where n is the size of the array and k is the number of digits for each number
int findNumbers1(vector<int>& nums) {
	int e = 0;
	for (auto num : nums) {
		if (is_even_digits(num))
			e++;
	}
	return e;
}

// Time Complexity - O(n)
int findNumbers2(vector<int>& nums) {
	int e = 0;
	for (auto num : nums) {
		int d = log10(num) + 1;
		if (d % 2 == 0)
			e++;
	}
	return e;
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

	cout << findNumbers1(nums) << endl;
	cout << findNumbers2(nums) << endl;

	return 0;
}

