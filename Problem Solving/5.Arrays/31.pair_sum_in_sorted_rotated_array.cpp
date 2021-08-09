/*

Alice and Bob always loved to play with arrays. Alice took a sorted array and rotated it clockwise for a certain number of times.
For Example:
Alice took a sorted array = [4,6,8,10,11] and if she rotates it by 3, then the array becomes: [8, 10, 11, 4, 6].
After rotating a sorted array, Alice gave a number ‘K’ to Bob and asked him to search for a pair in an array whose sum is equal to K. Since Bob was busy preparing for his semester exams, he asked you to help him.
You are given an array of integers ARR and a number K. Your task is to find out whether there exists a pair in the array ARR with sum K or not. If there exists a pair then you can return TRUE else return FALSE;
Input Format:
The first line of input contains a single integer T, representing the number of test cases
Then the T test cases follow.

The first line of each test case contains a number N denoting the size of the array and an integer K representing the sum of pair.

The second line contains N space-separated distinct integers a1, a2, ..., aN — the array elements.
Output format:
For each test case print “YES” if Bob finds the pair else print “NO”.

The output of every test case will be printed in a separate line.
Note:
You don’t have to print anything, it has already been taken care of. Just implement the given function.
Follow Up:
Can you do this in O(N) time, and without using any extra space?
Constraints
1<= T <=100
2 <= N <= 10000
-10^8 <= A[i] <= 10^8
-10^8 <= k <= 10^8

Time limit: 1 second
Sample Input 1:
3
5 4
5 7 9 1 3
4 2
8 10 11 1
6 -7
-3 3 6 -5 -4 1
Sample Output 1
YES
NO
YES
Explanation For Sample Output 1:
For the first array [5,7,9,1,3] there exists a pair (1,3) whose sum is equal to 4.

For the second array, there exists no pair whose sum is equal to 2.

For the third array, there exists a pair (-3,-4) whose sum is equal to -7.
Sample Input 2:
3
6 -10
3 4 5 6 1 2
2 0
10 -10
4 -20
5 6 7 1
Sample Output 2:
NO
YES
NO

*/

#include<bits/stdc++.h>
using namespace std;

int findMinIndex(vector<int> & nums) {
	int i;
	for (i = 1; i < nums.size(); i++) {
		if (nums[i] <= nums[i - 1])
			return i;
	}
	return 0;
}


// Time Complexity - O(n)
bool find_target_sum_pair(vector<int> & nums, int target) {
	int si = findMinIndex(nums);
	int ei = (si == 0) ? (nums.size() - 1) : (si - 1);

	for (int i = si, j = ei; i != j;) {
		if (nums[i] + nums[j] == target) {
			return true;
		} else if (nums[i] + nums[j] < target) {
			i++;
			i %= nums.size();
		} else {
			j--;
			if (j < 0) {
				j += nums.size();
			}
		}
	}

	return false;
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

	int target;
	cin >> target;

	cout << find_target_sum_pair(nums, target) << endl;

	return 0;
}


