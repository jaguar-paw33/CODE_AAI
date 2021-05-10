/*

Preorder : Root---Left---Right
Inorder : Left---Root---Right
Postorder : Left---Right---Root

*/

#include<bits/stdc++.h>
#include"level_wise_input_output.h"
using namespace std;

void preorder(binaryTreeNode<int> * root) {
	if (!root)
		return;
	cout << root->data << " ";
	preorder(root->left);
	preorder(root->right);
}

void inorder(binaryTreeNode<int> * root) {
	if (!root)
		return;
	inorder(root->left);
	cout << root->data << " ";
	inorder(root->right);
}

void postorder(binaryTreeNode<int> * root) {
	if (!root)
		return;
	postorder(root->left);
	postorder(root->right);
	cout << root->data << " ";
}

int main() {
	binaryTreeNode<int> * root = takeInput();
	cout << endl << "Preorder : ";
	preorder(root);
	cout << endl << "Inorder : ";
	inorder(root);
	cout << endl << "Postorder : ";
	postorder(root);
	return 0;
}