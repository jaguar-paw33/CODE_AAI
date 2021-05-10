#include<bits/stdc++.h>
#include"binary_tree_node.h"
using namespace std;


binaryTreeNode<int> * takeInput() {
	int rootData;
	cout << "Enter Root Data : ";
	cin >> rootData;
	binaryTreeNode<int> * root = new binaryTreeNode<int>(rootData);
	queue<binaryTreeNode<int>*> pending;
	pending.push(root);

	while (!pending.empty()) {
		binaryTreeNode<int> * temp = pending.front();
		pending.pop();
		binaryTreeNode<int> * lChild = NULL;
		binaryTreeNode<int> * rChild = NULL;

		int lData;
		int rData;

		cout << "Enter Left Child :";
		cin >> lData;
		if (lData != -1) {
			lChild = new binaryTreeNode<int>(lData);
			pending.push(lChild);
		}

		cout << "Enter Right Child :";
		cin >> rData;
		if (rData != -1) {
			rChild = new binaryTreeNode<int>(rData);
			pending.push(rChild);
		}
		temp->left = lChild;
		temp->right = rChild;
	}
	return root;
}

void printBinaryTree(binaryTreeNode<int> * root) {
	if (!root)
		return;
	queue<binaryTreeNode<int> *> pending;
	pending.push(root);
	while (!pending.empty()) {
		binaryTreeNode<int> * temp = pending.front();
		pending.pop();
		cout << temp->data << ":";
		if (temp->left) {
			cout << "L:" << temp->left->data << ",";
			pending.push(temp->left);
		} else {
			cout << "L:" << -1 << ",";
		}
		if (temp->right) {
			cout << "R:" << temp->right->data;
			pending.push(temp->right);
		} else {
			cout << "R:" << -1;

		}
		cout << endl;
	}
}