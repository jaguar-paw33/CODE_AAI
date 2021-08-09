/*

Given an array arr, replace every element in that array with the greatest element among the elements to its right, and replace the last element with -1.

After doing so, return the array.

Example 1:

Input: arr = [17,18,5,4,6,1]

Output: [18,6,6,6,1,-1]

Constraints:

1 <= arr.length <= 10^4

1 <= arr[i] <= 10^5


Level: Easy

Problem Practice link: https://leetcode.com/problems/replace-elements-with-greatest-element-on-right-side/

Companies Asked in: Amazon

*/


#include<bits/stdc++.h>
using namespace std;

vector<int> replace(vector<int> & arr) {
	int max_val = arr[arr.size() - 1];

	for (int i = arr.size() - 1; i >= 0; i--) {
		if (arr[i] < max_val) {
			arr[i] = max_val;
		} else {
			int temp = arr[i];
			arr[i] = max_val;
			max_val = temp;
		}
	}

	arr[arr.size() - 1] = -1;

	return arr;
}

int main() {
	int n;
	cin >> n;

	int v;

	vector<int> arr;

	while (n--) {
		cin >> v;
		arr.push_back(v);
	}

	vector<int> ans = replace(arr);

	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}

	return 0;
}