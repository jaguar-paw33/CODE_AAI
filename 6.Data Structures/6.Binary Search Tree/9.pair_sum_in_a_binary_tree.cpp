/*

Given a binary tree and an integer S, print all the pair of nodes whose sum equals S.

Note:
1. Assume the given binary tree contains all unique elements.
2. In a pair, print the smaller element first. Order of different pairs doesn't matter.

Input format :
The first line of input contains data of the nodes of the tree in level order form. The data of the nodes of the tree is separated by space. If any node does not have a left or right child, take -1 in its place. Since -1 is used as an indication whether the left or right nodes exist, therefore, it will not be a part of the data of any node.
The following line of input contains an integer, that denotes the value of S.

Output Format :
Print each pair in a new line, as described in the task.

Constraints:
Time Limit: 1 second

Sample Input 1:
5 10 6 2 3 -1 -1 -1 -1 -1 9 -1 -1
15
Sample Output 1:
5 10
6 9

*/

#include<bits/stdc++.h>
#include"binary_search_tree.h"
#include"linked_list.h"
using namespace std;

void getArr(binaryTreeNode<int> * root, vector<int> & v) {
	if (!root)
		return;
	v.push_back(root->data);
	getArr(root->left, v);
	getArr(root->right, v);
}

void pair_sum(binaryTreeNode<int> *root, int sum) {
	vector<int> v;
	getArr(root, v);
	sort(v.begin(), v.end());
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