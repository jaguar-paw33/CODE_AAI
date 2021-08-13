#include<bits/stdc++.h>
#include"binary_tree_node_class.h"
using namespace std;


binaryTreeNode * takeInput() {
	int data;
	cin >> data;

	if (data == -1)
		return NULL;

	binaryTreeNode * root = new binaryTreeNode(data);

	queue<binaryTreeNode *> pending;
	pending.push(root);

	while (!pending.empty()) {
		binaryTreeNode * temp = pending.front();
		pending.pop();

		int leftData;
		cin >> leftData;

		if (leftData != -1) {
			binaryTreeNode * left = new binaryTreeNode(leftData);
			temp->left = left;
			pending.push(temp->left);
		}

		int rightData;
		cin >> rightData;

		if (rightData != -1) {
			binaryTreeNode * right = new binaryTreeNode (rightData);
			temp->right = right;
			pending.push(temp->right);
		}

	}

	return root;
}


void levelOrderTraversal(binaryTreeNode * root) {
	if (!root)
		return;

	queue<binaryTreeNode *> pending;
	pending.push(root);

	while (!pending.empty()) {
		binaryTreeNode * temp = pending.front();
		pending.pop();
		cout << temp->data << " ";
		if (temp->left)
			pending.push(temp->left);
		if (temp->right)
			pending.push(temp->right);
	}
}