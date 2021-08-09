/*

We have some permutation A of [0, 1, ..., N - 1], where N is the length of A.

The number of (global) inversions is the number of i < j with 0 <= i < j < N and A[i] > A[j].

The number of local inversions is the number of i with 0 <= i < N and A[i] > A[i+1].

Return true if and only if the number of global inversions is equal to the number of local inversions.

Example 1:

Input: A = [1,0,2]

Output: true

Explanation: There is 1 global inversion, and 1 local inversion.

Example 2:

Input: A = [1,2,0]

Output: false

Explanation: There are 2 global inversions, and 1 local inversion.

Level: Medium

Problem Practice link: https://leetcode.com/problems/global-and-local-inversions/

Python Executable code: https://onlinegdb.com/BJAE1Dt-8

*/



// One approach is to find the number of global and local inversions explicitly
// but finding global inversions using merge sort will take O(nlogn) time but we need to solve
// this problem in O(n) time.


// Another approach is to find the cases when we can have equal global and local inversions
// then simply return true or false based on the conidition.

#include<bits/stdc++.h>
using namespace std;

bool global_equal_local(vector<int> & nums) {
	// All local inversions are also global inversions
	// To have same global and local inversions all the absoulte difference between the element
	// and its index cannot be greater than 1. i.e. the element i can either be at i-1th index or ith index or i+1th index.

	for (int i = 0; i < nums.size(); i++) {
		if (abs(nums[i] - i) > 1)
			return false;
	}
	return true;
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

	cout << global_equal_local(nums) << endl;

	return 0;
}