/*

Given a Binary tree, find the largest BST subtree. That is, you need to find the BST with maximum height in the given binary tree. You have to return the height of largest BST.

Input format :
The first line of input contains data of the nodes of the tree in level order form. The data of the nodes of the tree is separated by space. If any node does not have left or right child, take -1 in its place. Since -1 is used as an indication whether the left or right nodes exist, therefore, it will not be a part of the data of any node.

Output format:
The first and only line of output contains the height of the largest BST.

Constraints:
Time Limit: 1 second

Sample Input 1:
5 10 6 2 3 -1 -1 -1 -1 -1 9 -1 -1
Sample Output 1:
2

*/

#include<bits/stdc++.h>
#include"level_wise_input_output.h"
using namespace std;

class constraints {
public:
	int height;
	int min_val;
	int max_val;
	bool isBST;

	constraints() {
		height = 0;
		min_val = INT_MAX;
		max_val = INT_MIN;
		isBST = true;
	}
};

constraints largest_bst(binaryTreeNode<int> * root) {
	if (!root) {
		constraints c;
		return c;
	}
	constraints l = largest_bst(root->left);
	constraints r = largest_bst(root->right);
	constraints ans;
	ans.min_val = min(root->data, min(l.min_val, r.min_val));
	ans.max_val = max(root->data, max(l.max_val, r.max_val));
	ans.isBST = l.isBST && r.isBST && (root->data >= l.max_val) && (root->data < r.min_val);
	if (ans.isBST)
		ans.height = 1;
	ans.height += max(l.height, r.height);
	return ans;
}

int main() {
	binaryTreeNode<int> * root = takeInput();
	cout << largest_bst(root).height << endl;
	delete root;
	return 0;
}