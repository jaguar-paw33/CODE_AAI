/*

Given the root of a binary tree, invert the tree, and return its root.



Example 1:


Input: root = [4,2,7,1,3,6,9]
Output: [4,7,2,9,6,3,1]
Example 2:


Input: root = [2,1,3]
Output: [2,3,1]
Example 3:

Input: root = []
Output: []


Constraints:

The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100

*/

#include<bits/stdc++.h>
#include"level_wise_input_output.h"
using namespace std;

binaryTreeNode* invertTree(binaryTreeNode* root) {
	if (!root || (!root->left && !root->right))
		return root;

	root->left = invertTree(root->left);
	root->right = invertTree(root->right);

	binaryTreeNode * temp = root->left;
	root->left = root->right;
	root->right = temp;

	return root;
}

int main() {
	binaryTreeNode * root = takeInput();

	root = invertTree(root);

	levelOrderTraversal(root);

	delete root;

	return 0;
}

