#include<bits/stdc++.h>
#include"binary_tree_node.h"
using namespace std;


binaryTreeNode<int> *takeInput() {
	int data;
	cout << "Enter Data : ";
	cin >> data;
	if (data == -1)
		return NULL;
	binaryTreeNode<int> * root = new binaryTreeNode<int>(data);
	root->left = takeInput();
	root->right = takeInput();
	return root;
}

void printBinaryTree(binaryTreeNode<int> * root) {
	if (!root)
		return;
	cout << root->data << ":";
	if (root->left) {
		cout << "L:" << root->left->data << ",";
	} else {
		cout << "L:" << -1 << ",";
	}
	if (root->right) {
		cout << "R:" << root->right->data;
	} else {
		cout << "R:" << -1;
	}
	cout << endl;
	printBinaryTree(root->left);
	printBinaryTree(root->right);
}