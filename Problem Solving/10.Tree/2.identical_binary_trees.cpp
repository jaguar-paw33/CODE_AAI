/*

Given the roots of two binary trees p and q, write a function to check if they are the same or not.

Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.



Example 1:


Input: p = [1,2,3], q = [1,2,3]
Output: true
Example 2:


Input: p = [1,2], q = [1,null,2]
Output: false
Example 3:


Input: p = [1,2,1], q = [1,1,2]
Output: false


Constraints:

The number of nodes in both trees is in the range [0, 100].
-10^4 <= Node.val <= 10^4

Level: Easy

Problem Practice Link: https://leetcode.com/problems/same-tree/

C Program: https://ideone.com/dwsXXA

Python code: https://onlinegdb.com/HkK1PdMpH


*/

#include<bits/stdc++.h>
#include"level_wise_input_output.h"
using namespace std;

bool isSameTree(binaryTreeNode* p, binaryTreeNode* q) {
	if (!p && !q)
		return true;
	else if (!p || !q)
		return false;
	if (p->data != q->data)
		return false;
	return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

int main() {
	binaryTreeNode * root1 = takeInput();
	binaryTreeNode * root2 = takeInput();

	cout << isSameTree(root1, root2) << endl;

	delete root1, root2;

	return 0;
}