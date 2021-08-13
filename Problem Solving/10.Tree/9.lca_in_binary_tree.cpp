/*

Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”



Example 1:


Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
Output: 3
Explanation: The LCA of nodes 5 and 1 is 3.
Example 2:


Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
Output: 5
Explanation: The LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.
Example 3:

Input: root = [1,2], p = 1, q = 2
Output: 1


Constraints:

The number of nodes in the tree is in the range [2, 105].
-109 <= Node.val <= 109
All Node.val are unique.
p != q
p and q will exist in the tree.

Problem Practice link: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/

C Program: https://ideone.com/eSv6u1

*/

#include<bits/stdc++.h>
#include"level_wise_input_output.h"
using namespace std;

int isSumProperty(binaryTreeNode *root)
{
	if (!root || (!root->left && !root->right))
		return 1;
	int s = 0;
	if (root->left)
		s += root->left->data;
	if (root->right)
		s += root->right->data;
	if (s != root->data)
		return 0;
	return isSumProperty(root->left) &&  isSumProperty(root->right);
}

int main() {
	binaryTreeNode * root = takeInput();

	cout << isSumProperty(root) << endl;

	delete root;

	return 0;
}