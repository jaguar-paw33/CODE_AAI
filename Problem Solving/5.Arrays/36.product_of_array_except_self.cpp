/*

Given an array nums of n integers where n > 1,  return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].



Example:





Input:  [1,2,3,4]

Output: [24,12,8,6]



Constraint: It's guaranteed that the product of the elements of any prefix or suffix of the array (including the whole array) fits in a 32 bit integer.



Note: Please solve it without division and in O(n).



Follow up:

Could you solve it with constant space complexity? (The output array does not count as extra space for the purpose of space complexity analysis.)



Level: Medium

Problem Practice link: https://leetcode.com/problems/product-of-array-except-self/

Python Executable code: https://onlinegdb.com/SyvqpV3ZU


Similar Problems:

Maximum Product Subarray: https://leetcode.com/problems/maximum-product-subarray/

Paint House: https://leetcode.com/problems/paint-house-ii/

*/

#include<bits/stdc++.h>
using namespace std;


// Time Complexity - O(n) and Space Complexity - O(1)
vector<int> get_product(vector<int> & nums) {
	vector<int> ans;

	ans.push_back(1);

	for (int i = 1; i < nums.size(); i++) {
		ans.push_back(nums[i - 1]*ans[i - 1]);
	}

	int p = nums[nums.size() - 1];

	for (int i = nums.size() - 2; i >= 0; i--) {
		ans[i] *= p;
		p *= nums[i];
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

	vector<int> ans = get_product(nums);

	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}

	return 0;
}
