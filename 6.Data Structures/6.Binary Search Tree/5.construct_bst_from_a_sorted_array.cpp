/*

Given a sorted integer array A of size n, which contains all unique elements. You need to construct a balanced BST from this input array. Return the root of constructed BST.

Note: If array size is even, take first mid as root.

Input format:
The first line of input contains an integer, which denotes the value of n. The following line contains n space separated integers, that denote the values of array.

Output Format:
The first and only line of output contains values of BST nodes, printed in pre order traversal.

Constraints:
Time Limit: 1 second

Sample Input 1:
7
1 2 3 4 5 6 7
Sample Output 1:
4 2 1 3 6 5 7

*/

#include<bits/stdc++.h>
#include"binary_search_tree.h"
using namespace std;

binaryTreeNode<int> * constructBSTFromSortedArray(int * arr, int si, int ei) {
	if (si > ei)
		return NULL;
	int mid = si + (ei - si) / 2;
	binaryTreeNode<int> * root = new binaryTreeNode<int>(arr[mid]);
	root->left = constructBSTFromSortedArray(arr, si, mid - 1);
	root->right = constructBSTFromSortedArray(arr, mid + 1, ei);
	return root;
}

int main() {
	int n;
	cin >> n;
	int * arr = new int [n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	binaryTreeNode<int> * root = constructBSTFromSortedArray(arr, 0, n - 1);
	printTree(root);
	delete arr;
	delete root;
	return 0;
}
