/*

Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.

Example 1:

Input: [3,2,1,5,6,4] and k = 2

Output: 5

Example 2:

Input: [3,2,3,1,2,4,5,5,6] and k = 4

Output: 4

Note:

You may assume k is always valid, 1 ≤ k ≤ array's length.

Level: Medium

Companies Asked in: Amazon, Google, Microsoft, Facebook etc

Problem Practice link: https://leetcode.com/problems/kth-largest-element-in-an-array/

Python Code: https://onlinegdb.com/HkOlJRxUv

Similar Questions:

1. Wiggle Sort II: https://leetcode.com/problems/wiggle-sort-ii/

2. Top K frequent Elements: https://leetcode.com/problems/top-k-frequent-elements/

3. Third maximum numberhttps://leetcode.com/problems/third-maximum-number/

*/

#include<bits/stdc++.h>
using namespace std;

// Time Complexity - O(nlogn)
int kth_largest1(vector<int> & nums, int k) {
	sort(nums.begin(), nums.end());
	return nums[nums.size() - k];
}


// Time Complexity - O(nlogk)
int kth_largest2(vector<int> & nums, int k) {
	priority_queue<int, vector<int>, greater<int>> minHeap;

	for (int i = 0; i < k; i++) {
		minHeap.push(nums[i]);
	}

	for (int i = k; i < nums.size(); i++) {
		minHeap.push(nums[i]);
		minHeap.pop();
	}

	return minHeap.top();
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

	int k;
	cin >> k;

	cout << kth_largest1(nums, k) << endl;
	cout << kth_largest2(nums, k) << endl;

	return 0;
}