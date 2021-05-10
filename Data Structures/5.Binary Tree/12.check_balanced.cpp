/*

Given a binary tree, check if it is balanced. Return true if given binary tree is balanced, false otherwise.

Balanced Binary Tree:

A empty binary tree or binary tree with zero nodes is always balanced. For a non empty binary tree to be balanced, following conditions must be met:

1. The left and right subtrees must be balanced.
2. |hL - hR| <= 1, where hL is the height or depth of left subtree and hR is the height or depth of right subtree.

Input format:
The first line of input contains data of the nodes of the tree in level order form. The data of the nodes of the tree is separated by space. If any node does not have a left or right child, take -1 in its place. Since -1 is used as an indication whether the left or right nodes exist, therefore, it will not be a part of the data of any node.

Output format
The first and only line of output contains true or false.

Constraints
Time Limit: 1 second

Sample Input 1 :
5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1
Sample Output 1 :
false

Sample Input 2 :
1 2 3 -1 -1 -1 -1
Sample Output 2 :
true

*/


#include<bits/stdc++.h>
#include"level_wise_input_output.h"
using namespace std;

pair<int, bool> isBalanced(binaryTreeNode<int>*root) {
	if (!root) {
		pair<int, bool> p(0, true);
		return p;
	}
	pair<int, bool> l = isBalanced(root->left);
	pair<int, bool> r = isBalanced(root->right);
	pair<int, bool> ans;
	ans.first = max(l.first, r.first) + 1;
	ans.second = l.second && r.second && (abs(l.first - r.first) <= 1);
	return ans;
}

int main() {
	binaryTreeNode<int> * root = takeInput();
	cout << (isBalanced(root).second ? "true" : "false") << endl;
	delete root;
	return 0;
}