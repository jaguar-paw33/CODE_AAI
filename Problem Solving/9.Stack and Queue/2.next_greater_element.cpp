/*

The next greater element of some element x in an array is the first greater element that is to the right of x in the same array.

You are given two distinct 0-indexed integer arrays nums1 and nums2, where nums1 is a subset of nums2.

For each 0 <= i < nums1.length, find the index j such that nums1[i] == nums2[j] and determine the next greater element of nums2[j] in nums2. If there is no next greater element, then the answer for this query is -1.

Return an array ans of length nums1.length such that ans[i] is the next greater element as described above.



Example 1:

Input: nums1 = [4,1,2], nums2 = [1,3,4,2]
Output: [-1,3,-1]
Explanation: The next greater element for each value of nums1 is as follows:
- 4 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.
- 1 is underlined in nums2 = [1,3,4,2]. The next greater element is 3.
- 2 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.
Example 2:

Input: nums1 = [2,4], nums2 = [1,2,3,4]
Output: [3,-1]
Explanation: The next greater element for each value of nums1 is as follows:
- 2 is underlined in nums2 = [1,2,3,4]. The next greater element is 3.
- 4 is underlined in nums2 = [1,2,3,4]. There is no next greater element, so the answer is -1.


Constraints:

1 <= nums1.length <= nums2.length <= 1000
0 <= nums1[i], nums2[i] <= 104
All integers in nums1 and nums2 are unique.
All the integers of nums1 also appear in nums2.


Follow up: Could you find an O(nums1.length + nums2.length) solution?

Problem Practise Link - https://leetcode.com/problems/next-greater-element-i/

Similar Questions:

Next Greater element II: https://leetcode.com/problems/next-greater-element-ii/

Next Greater Element III: https://leetcode.com/problems/next-greater-element-iii/

C-Code: https://ideone.com/7hUHKy

Python Code: https://onlinegdb.com/SkdRWklnB

*/

#include<bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

	stack<int> s;
	unordered_map<int, int> m;

	int nums2_greater[nums2.size()];

	for (int i = nums2.size() - 1; i >= 0; i--) {
		if (s.empty()) {
			nums2_greater[i] = -1;
		} else {
			if (s.top() <= nums2[i]) {
				while (s.size() && s.top() <= nums2[i]) {
					s.pop();
				}
				if (s.size()) {
					nums2_greater[i] = s.top();
				} else {
					nums2_greater[i] = -1;
				}
			} else {
				nums2_greater[i] = s.top();
			}
		}
		s.push(nums2[i]);
		m[nums2[i]] = i;
	}

	vector<int> ans;

	for (int i = 0; i < nums1.size(); i++) {
		if (m.find(nums1[i]) != m.end()) {
			ans.push_back(nums2_greater[m[nums1[i]]]);
		}
	}

	return ans;
}

int main() {

	int n1, n2;
	cin >> n1 >> n2;

	vector<int> nums1, nums2;

	int v;

	while (n1--) {
		cin >> v;
		nums1.push_back(v);
	}

	while (n2--) {
		cin >> v;
		nums2.push_back(v);
	}

	vector<int> ans = nextGreaterElement(nums1, nums2);

	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}

	return 0;

}