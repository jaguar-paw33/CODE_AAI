/*

Preorder_recursive : Root---Left---Right
Inorder_recursive : Left---Root---Right
Postorder : Left---Right---Root

*/

#include<bits/stdc++.h>
#include"level_wise_input_output.h"
using namespace std;

void preorder_recursive(binaryTreeNode<int> * root) {
	if (!root)
		return;
	cout << root->data << " ";
	preorder_recursive(root->left);
	preorder_recursive(root->right);
}

void preorder_iterative(binaryTreeNode<int> * root) {
	if (!root)
		return;
	stack<binaryTreeNode<int> *> pending;
	pending.push(root);

	while (!pending.empty()) {
		binaryTreeNode<int> * temp = pending.top();
		pending.pop();
		cout << temp->data << " ";
		if (temp->right)
			pending.push(temp->right);
		if (temp->left)
			pending.push(temp->left);
	}
}

void inorder_recursive(binaryTreeNode<int> * root) {
	if (!root)
		return;
	inorder_recursive(root->left);
	cout << root->data << " ";
	inorder_recursive(root->right);
}

void inorder_iterative(binaryTreeNode<int> * root) {

	binaryTreeNode<int> * cur = root;
	stack<binaryTreeNode<int> *> pending;

	while (!pending.empty() || cur) {
		while (cur) {
			pending.push(cur);
			cur = cur->left;
		}
		cur = pending.top();
		pending.pop();
		cout << cur->data << " ";
		cur = cur->right;
	}
}

void postorder_recursive(binaryTreeNode<int> * root) {
	if (!root)
		return;
	postorder_recursive(root->left);
	postorder_recursive(root->right);
	cout << root->data << " ";
}

void postorder_iterative_using_2_stacks(binaryTreeNode<int> * root) {
	stack<binaryTreeNode<int> *> recursiveStack, resultStack;
	recursiveStack.push(root);

	while (!recursiveStack.empty()) {
		resultStack.push(recursiveStack.top());
		recursiveStack.pop();
		if (resultStack.top()->left)
			recursiveStack.push(resultStack.top()->left);
		if (resultStack.top()->right)
			recursiveStack.push(resultStack.top()->right);
	}

	while (!resultStack.empty()) {
		cout << resultStack.top()->data << " ";
		resultStack.pop();
	}
}

void postorder_iterative_using_1_stack(binaryTreeNode<int> * root) {
	stack<binaryTreeNode<int>*> pending;
	pending.push(root);
	binaryTreeNode<int> * prev = NULL;
	while (!pending.empty()) {
		binaryTreeNode<int> * cur = pending.top();
		if (!prev || prev->left == cur || prev->right == cur) {
			if (cur->left)
				pending.push(cur->left);
			else if (cur->right)
				pending.push(cur->right);
			else {
				cout << cur->data << " ";
				pending.pop();
			}
		} else if (cur->left == prev) {
			if (cur->right)
				pending.push(cur->right);
		} else {
			cout << cur->data << " ";
			pending.pop();
		}
		prev = cur;
	}
}


int main() {
	binaryTreeNode<int> * root = takeInput();
	cout << endl << "Preorder Recursive : ";
	preorder_recursive(root);
	cout << endl << "Preorder Iterative : ";
	preorder_iterative(root);
	cout << endl << "Inorder Recursive : ";
	inorder_recursive(root);
	cout << endl << "Inorder Iterative : ";
	inorder_iterative(root);
	cout << endl << "Postorder Recursive : ";
	postorder_recursive(root);
	cout << endl << "Postorder Iterative using 2 Stacks : ";
	postorder_iterative_using_2_stacks(root);
	cout << endl << "Postorder Iterative using 1 Stack : ";
	postorder_iterative_using_1_stack(root);
	return 0;
}

// 8 6 10 5 7 -1 -1 -1 -1 9 11 -1 -1 -1 -1