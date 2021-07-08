/*

You are given with an integer k and an array of integers that contain numbers in random order. Write a program to find k largest numbers from given array. You need to save them in an array and return it.
Time complexity should be O(nlogk) and space complexity should be not more than O(k).

Order of elements in the output is not important.

Input Format :
Line 1 : Size of array (n)
Line 2 : Array elements (separated by space)
Line 3 : Integer k

Output Format :
k largest elements

Sample Input :
13
2 12 9 16 10 5 3 20 25 11 1 8 6
4
Sample Output :
12 16 20 25

*/

#include<bits/stdc++.h>
using namespace std;

vector<int> k_largest(int * arr, int n, int k) {
	priority_queue<int, vector<int>, greater<int>> pq;
	vector<int> ans;
	for (int i = 0; i < k; i++) {
		pq.push(arr[i]);
	}
	for (int i = k; i < n; i++) {
		pq.push(arr[i]);
		pq.pop();
	}
	while (!pq.empty()) {
		ans.push_back(pq.top());
		pq.pop();
	}
	return ans;
}

int main() {
	int n;
	cin >> n;
	int * arr = new int [n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int k;
	cin >> k;
	vector<int> ans = k_largest(arr, n, k);
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}
	delete [] arr;
	return 0;
}
