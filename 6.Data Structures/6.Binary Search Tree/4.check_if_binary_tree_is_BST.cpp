/*

Given a binary tree with N number of nodes, check if that input tree is BST (Binary Search Tree). If yes, return true, return false otherwise.

Note: Duplicate elements should be kept in the right subtree.

Input format :
The first line of input contains data of the nodes of the tree in level order form. The data of the nodes of the tree is separated by space. If any node does not have a left or right child, take -1 in its place. Since -1 is used as an indication whether the left or right nodes exist, therefore, it will not be a part of the data of any node.

Output format :
The first and only line of output contains either true or false.

Constraints :
Time Limit: 1 second

Sample Input 1 :
3 1 5 -1 2 -1 -1 -1 -1
Sample Output 1 :
true

Sample Input 2 :
5 2 10 0 1 -1 15 -1 -1 -1 -1 -1 -1
Sample Output 2 :
false

*/

#include<bits/stdc++.h>
#include"level_wise_input_output.h"
using namespace std;

class triplet {
public:
	int min_value;
	int max_value;
	bool check_BST;

	triplet() {
		min_value = INT_MAX;
		max_value = INT_MIN;
		check_BST = true;
	}
};

triplet isBSTHelper(binaryTreeNode<int> * root) {
	if (!root) {
		triplet t;
		return t;
	}
	triplet l  = isBSTHelper(root->left);
	triplet r  = isBSTHelper(root->right);
	triplet ans;
	ans.min_value = min(root->data, min(l.min_value, r.min_value));
	ans.max_value = max(root->data, max(l.max_value, r.max_value));
	ans.check_BST = (root->data >= l.max_value) && (root->data < r.min_value) && l.check_BST && r.check_BST;
	return ans;
}

bool isBST(binaryTreeNode<int> * root) {
	return isBSTHelper(root).check_BST;
}

int main() {
	binaryTreeNode<int> * root = takeInput();
	cout << (isBST(root) ? "true" : "false") << endl;
	delete root;
	return 0;
}