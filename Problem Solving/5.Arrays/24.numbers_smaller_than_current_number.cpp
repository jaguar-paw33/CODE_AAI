/*

Given the array nums, for each nums[i] find out how many numbers in the array are smaller than it. That is, for each nums[i] you have to count the number of valid j's such that j != i and nums[j] < nums[i].

Return the answer in an array.

Example 1:

Input: nums = [8,1,2,2,3]

Output: [4,0,1,1,3]

Explanation:

For nums[0]=8 there exist four smaller numbers than it (1, 2, 2 and 3).

For nums[1]=1 does not exist any smaller number than it.

For nums[2]=2 there exist one smaller number than it (1).

For nums[3]=2 there exist one smaller number than it (1).

For nums[4]=3 there exist three smaller numbers than it (1, 2 and 2).

Example 2:

Input: nums = [6,5,4,8]

Output: [2,1,0,3]

Example 3:

Input: nums = [7,7,7,7]

Output: [0,0,0,0]

Constraints:

2 <= nums.length <= 500

0 <= nums[i] <= 100

*/


#include<bits/stdc++.h>
using namespace std;


// O(nlogn) approach
vector<int> nlogn_smallerNumbersThanCurrent(vector<int>& nums) {
	unordered_map<int, int> m;

	vector<int> temp;

	for (int i = 0; i < nums.size(); i++) {
		temp.push_back(nums[i]);
	}

	sort(temp.begin(), temp.end());

	for (int i = 0; i < temp.size(); i++) {
		if (m.find(temp[i]) != m.end())
			continue;
		else
			m[temp[i]] = i;
	}

	vector<int> ans;

	for (int i = 0; i < nums.size(); i++) {
		ans.push_back(m[nums[i]]);
	}

	return ans;
}

void compute_prefix_sum(int * arr, int n) {
	for (int i = 1; i < n; i++) {
		arr[i] += arr[i - 1];
	}
}


// O(n) approach only valid when we have the maximum number in array within the valid range
vector<int> n_smallerNumbersThanCurrent(vector<int> & nums) {
	int temp[101];
	for (int i = 0; i < 101; i++) {
		temp[i] = 0;
	}

	for (int i = 0; i < nums.size(); i++) {
		temp[nums[i]]++;
	}

	compute_prefix_sum(temp, 101);

	vector<int> ans;

	for (int i = 0; i < nums.size(); i++) {

		if (nums[i] == 0) // If the value is 0
			ans.push_back(0);
		else
			ans.push_back(temp[nums[i] - 1]); // Number of lesser values are at the index before the current value.
	}

	return ans;
}


int main() {
	int n;
	cin >> n;

	vector<int> nums;

	int v;

	for (int i = 0; i < n; i++) {
		cin >> v;
		nums.push_back(v);
	}

	vector<int> ans = nlogn_smallerNumbersThanCurrent(nums);

	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}

	return 0;
}
