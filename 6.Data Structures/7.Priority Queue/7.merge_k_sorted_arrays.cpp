/*

Given k different arrays, which are sorted individually (in ascending order). You need to merge all the given arrays such that output array should be sorted (in ascending order).

Input Format:
The first line of input contains an integer, that denotes value of k.
The following lines of input represent k sorted arrays. Each sorted array uses two lines of input. The first line contains an integer, that denotes the size of the array. The following line contains elements of the array.

Output Format:
The first and only line of output contains space separated elements of the merged and sorted array, as described in the task.

Constraints:
0 <= k <= 1000
0 <= n1, n2 <= 10000

Time Limit: 1 second

Sample Input 1:
4
3
1 5 9
2
45 90
5
2 6 78 100 234
1
0
Sample Output 1:
0 1 2 5 6 9 45 78 90 100 234

*/

#include<bits/stdc++.h>
using namespace std;

/*

	Time Complexity - O(k*n*log(k*n))
	Space Complexity - O(k*n)

	where k is the number of arrays to merge and n is the average length of the arrays
*/

vector<int> merge_k_sorted_arrays(vector<vector<int> *> arrays) {

	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 0; i < arrays.size(); i++) {
		for (int j = 0; j < arrays[i]->size(); j++) {
			pq.push(arrays[i]->at(j));
		}
	}
	vector<int> ans;
	while (!pq.empty()) {
		ans.push_back(pq.top());
		pq.pop();
	}
	return ans;
}

int main() {
	int k;
	cin >> k;
	vector<vector<int> *> arrays;
	for (int i = 0; i < k; i++) {
		int n;
		cin >> n;
		vector<int> * array = new vector<int>;
		while (n--) {
			int data;
			cin >> data;
			array->push_back(data);
		}
		arrays.push_back(array);
	}
	vector<int> ans = merge_k_sorted_arrays(arrays);
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}
	return 0;
}
