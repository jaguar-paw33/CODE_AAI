/*

Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.



Example 1:


Input: heights = [2,1,5,6,2,3]
Output: 10
Explanation: The above is a histogram where width of each bar is 1.
The largest rectangle is shown in the red area, which has an area = 10 units.
Example 2:


Input: heights = [2,4]
Output: 4


Constraints:

1 <= heights.length <= 10^5
0 <= heights[i] <= 10^4

*/

#include<bits/stdc++.h>
using namespace std;

// Time Complexity - O(n^2) and Space Complexity - O(n)
int largestRectangleArea(vector<int>& heights) {

	int max_area = INT_MIN;

	for (int i = 0; i < heights.size(); i++) {
		int li = i, ri = i;
		for (int j = i - 1; j >= 0; j--) {
			if (heights[j] >= heights[i])
				li = j;
			else
				break;
		}
		for (int j = i + 1; j < heights.size(); j++) {
			if (heights[j] >= heights[i])
				ri = j;
			else
				break;
		}
		max_area = max(max_area, heights[i] * (ri - li + 1));
	}
	return max_area;
}

int main() {
	int n;
	cin >> n;

	vector<int> heights;

	int h;

	while (n--) {
		cin >> h;
		heights.push_back(h);
	}

	cout << largestRectangleArea(heights) << endl;

	return 0;
}

