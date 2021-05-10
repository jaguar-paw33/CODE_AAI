/*

	Preorder 	: 	Root --- Children
	Postorder 	: 	Children --- Root

*/


#include<bits/stdc++.h>
#include"level_wise_input_output.h"
using namespace std;

void preorder(treeNode<int> * root) {
	if (!root)
		return;
	cout << root->data << " ";
	for (int i = 0; i < root->children.size(); i++) {
		preorder(root->children[i]);
	}
}


void postorder(treeNode<int> * root) {
	if (!root)
		return;
	for (int i = 0; i < root->children.size(); i++) {
		postorder(root->children[i]);
	}
	cout << root->data << " ";
}


int main() {
	treeNode<int> * root = takeInput();
	cout << endl << "Preorder : ";
	preorder(root);
	cout << endl << "Postorder : ";
	postorder(root);
	return 0;
}