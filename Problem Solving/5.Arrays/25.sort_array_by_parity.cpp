/*


Given an array A of non-negative integers, return an array consisting of all the even elements of A, followed by all the odd elements of A.

You may return any answer array that satisfies this condition.

Example 1:

Input: [3,1,2,4]

Output: [2,4,3,1]

The outputs [4,2,3,1], [2,4,1,3], and [4,2,1,3] would also be accepted.

Note:

1 <= A.length <= 5000

0 <= A[i] <= 5000

Level: Easy

Problem Practice Link: https://leetcode.com/problems/sort-array-by-parity/

Companies Asked in: Cisco, Amazon, VMWare, Oracle, Microsoft

*/


#include<bits/stdc++.h>
using namespace std;

vector<int> sort_by_parity(vector<int> & nums) {

	vector<int> ans;

	for (int i = 0; i < nums.size(); i++) {
		ans.push_back(nums[i]);
	}

	for (int i = 0, j = ans.size() - 1; i < j;) {
		if (ans[i] % 2) {
			if (ans[j] % 2 == 0) {
				int temp = ans[i];
				ans[i] = ans[j];
				ans[j] = temp;
				i++;
				j--;
			} else {
				j--;
			}
		} else {
			i++;
		}
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

	vector<int> ans = sort_by_parity(nums);

	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}

	return 0;
}
