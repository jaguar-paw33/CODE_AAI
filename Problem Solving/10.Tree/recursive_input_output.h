#include<bits/stdc++.h>
#include"binary_tree_node_class.h"
using namespace std;

binaryTreeNode * takeInput() {
	int data;
	cin >> data;

	if (data == -1)
		return NULL;

	binaryTreeNode * root = new binaryTreeNode(data);

	root->left = takeInput();
	root->right = takeInput();

	return root;
}

void printTree(binaryTreeNode * root) {
	if (!root)
		return;
	cout << root->data << " ";
	printTree(root->left);
	printTree(root->right);
}