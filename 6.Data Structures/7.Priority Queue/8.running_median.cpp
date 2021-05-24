/*

You are given a stream of N integers. For every i-th integer added to the running list of integers, print the resulting median.

Print only the integer part of the median.

Input Format :
The first line of input contains an integer N, denoting the number of integers in the stream.

The second line of input contains 'N' integers separated by a single space.

Output Format :
Print the running median for every integer added to the running list in one line (space-separated).

Input Constraints
0 <= N <= 10^5
1 <= Ai <= 10^5

Time Limit: 1 sec

Sample Input 1 :
6
6 2 1 3 7 5
Sample Output 1 :
6 4 2 2 3 4

Explanation of Sample Output 1 :
S = {6}, median = 6
S = {6, 2} -> {2, 6}, median = 4
S = {6, 2, 1} -> {1, 2, 6}, median = 2
S = {6, 2, 1, 3} -> {1, 2, 3, 6}, median = 2
S = {6, 2, 1, 3, 7} -> {1, 2, 3, 6, 7}, median = 3
S = {6, 2, 1, 3, 7, 5} -> {1, 2, 3, 5, 6, 7}, median = 4

Sample Input 2 :
5
5 4 3 2 1
Sample Output 2 :
5 4 4 3 3

*/

#include<bits/stdc++.h>
using namespace std;

void running_median(int * arr, int n) {

	if (n <= 0)
		return;

	priority_queue<int> maxpq;
	priority_queue<int, vector<int>, greater<int>> minpq;

	maxpq.push(arr[0]);
	cout << arr[0] << " ";

	for (int i = 1; i < n; i++) {
		if (maxpq.top() < arr[i]) {
			minpq.push(arr[i]);
		} else {
			maxpq.push(arr[i]);
		}
		int s1 = int(maxpq.size());
		int s2 = int(minpq.size());
		if (s1 - s2 > 1) {
			minpq.push(maxpq.top());
			maxpq.pop();
		} else if (s2 - s1 > 1) {
			maxpq.push(minpq.top());
			minpq.pop();
		}
		if ((s1 + s2) % 2 == 0) {
			cout << (minpq.top() + maxpq.top()) / 2 << " ";
		} else {
			cout << (s1 > s2 ? maxpq.top() : minpq.top()) << " ";
		}
	}
}

int main() {
	int n;
	cin >> n;
	int * arr = new int [n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	running_median(arr, n);
	delete [] arr;
	return 0;
}