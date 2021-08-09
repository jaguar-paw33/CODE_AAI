/*

Given a non-empty array of integers, every element appears twice except for one. Find that single one.

Note:

Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Example 1:

Input: [2,2,1]

Output: 1

Example 2:

Input: [4,1,2,1,2]

Output: 4

Level: Easy

Problem Practice link: https://leetcode.com/problems/single-number/

Python Executable code: https://onlinegdb.com/SJ1p4B2W8

Companies Asked in: Amazon, Google, Microsoft, Facebook, Oracle, Adobe, Airbnb


Similar Problems:

1. Single Number II: https://leetcode.com/problems/single-number-ii/

2. Single Number III: https://leetcode.com/problems/single-number-iii/

3. Missing Number: https://leetcode.com/problems/missing-number/

4. Find the Duplicate Number: https://leetcode.com/problems/find-the-duplicate-number/

*/

#include<bits/stdc++.h>
using namespace std;

int singleNumber(vector<int>& nums) {
	int ans = 0;
	for (auto num : nums) {
		ans ^= num;
	}
	return ans;
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

	cout << singleNumber(nums) << endl;

	return 0;

}
