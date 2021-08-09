/*

Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.



Example 1:

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
Example 2:

Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.


Constraints:

1 <= intervals.length <= 104
intervals[i].length == 2
0 <= starti <= endi <= 104


Level: Medium

Problem Practice link: https://leetcode.com/problems/merge-intervals/

Python Executable code: https://onlinegdb.com/S1RbdS3ZL



Similar Problems:

1. Meeting Rooms: https://leetcode.com/problems/meeting-rooms/

2. Partition labels: https://leetcode.com/problems/partition-labels/

3. Insert Interval: https://leetcode.com/problems/insert-interval/

4. Range Module: https://leetcode.com/problems/range-module/

*/

vector<vector<int>> merge(vector<vector<int>>& intervals) {
	vector<vector<int>> ans;

	sort(intervals.begin(), intervals.end());

	vector<int> t1;
	vector<int> t2;

	if (intervals.size() == 1)
		return intervals;

	for (int i = 0; i < intervals.size() - 1; i++) {

		if (!t1.size())
			t1 = intervals[i];

		t2 = intervals[i + 1];

		if (t1[1] >= t2[0]) {

			t2[0] = t1[0];

			if (t1[1] > t2[1])
				t2[1] = t1[1];

			t1 = t2;

			if (i == intervals.size() - 2)
				ans.push_back(t1);

		} else {
			ans.push_back(t1);

			if (i == intervals.size() - 2 && t1 != t2)
				ans.push_back(t2);

			t1.pop_back();
			t1.pop_back();
		}
	}
	return ans;
}

#includ