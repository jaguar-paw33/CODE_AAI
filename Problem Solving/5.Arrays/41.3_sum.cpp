/*

Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.



Note:



The solution set must not contain duplicate triplets.



Example:





Given array nums = [-1, 0, 1, 2, -1, -4],



A solution set is:

[

  [-1, 0, 1],

  [-1, -1, 2]

]



Level : Medium



Problem Practice Link: https://leetcode.com/problems/3sum/


Similar Problems:

1. Two Sum Problem: https://leetcode.com/problems/two-sum/

2. 3Sum Closest: https://leetcode.com/problems/3sum-closest/

3. 4Sum: https://leetcode.com/problems/4sum/

4. 3Sum Smaller: https://leetcode.com/problems/3sum-smaller/

*/

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> find_3_pair(vector<int> & nums) {

	vector<vector<int>> results;

	if (nums.size() < 3)
		return results;

	sort(nums.begin(), nums.end());

	for (int i = 0; i < nums.size() - 2; i++) {

		if (i > 0 && nums[i - 1] == nums[i])
			continue;

		for (int j = i + 1, k = nums.size() - 1; j < k;) {
			if (nums[i] + nums[j] + nums[k] == 0) {

				results.push_back({nums[i], nums[j], nums[k]});
				j++;
				k--;

			} else if (nums[i] + nums[j] + nums[k] < 0) {
				j++;
			} else {
				k--;
			}
		}
	}

	set<vector<int>> ans(results.begin(), results.end());

	results.assign(ans.begin(), ans.end());

	return results;

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

	vector<vector<int>> ans = find_3_pair(nums);

	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i][0] << " " << ans[i][1] << " " << ans[i][2] << endl;
	}

	return 0;
}
