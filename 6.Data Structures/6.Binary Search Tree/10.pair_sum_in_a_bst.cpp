/*

Given a binary search tree and an integer S, find pair of nodes in the BST which sum to S. You can use extra space of the order of O(log n).

Note:
1. Assume BST contains all unique elements.
2. In a pair, print the smaller element first.

Input Format :
The first line of input contains data of the nodes of the tree in level order form. The data of the nodes of the tree is separated by space. If any node does not have left or right child, take -1 in its place. Since -1 is used as an indication whether the left or right nodes exist, therefore, it will not be a part of the data of any node.
The following line of input contains an integer, that denotes the value of S.

Output format:
You have to print each pair in a different line (pair elements separated by space). The order of different pairs, to be printed, does not matter.

Constraints:
Time Limit: 1 second

Sample Input 1:
8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
12
Sample Output 1:
2 10
5 7

*/

#include<bits/stdc++.h>
#include"binary_search_tree.h"
using namespace std;

void getArr(binaryTreeNode<int> * root, vector<int> & v) {
	if (!root)
		return;
	getArr(root->left, v);
	v.push_back(root->data);
	getArr(root->right, v);
}

void pair_sum(binaryTreeNode<int> * root, int sum) {
	if (!root)
		return;
	vector<int> v;
	getArr(root, v);
	for (int i = 0, j = v.size() - 1; i < j;) {
		if (v[i] + v[j] == sum) {
			cout << v[i] << " " << v[j] << endl;
			i++;
			j--;
		} else if (v[i] + v[j] < sum) {
			i++;
		} else {
			j--;
		}
	}
}

int main() {
	binaryTreeNode<int> * root = takeInput();
	int sum;
	cin >> sum;
	pair_sum(root, sum);
	delete root;
	return 0;
}