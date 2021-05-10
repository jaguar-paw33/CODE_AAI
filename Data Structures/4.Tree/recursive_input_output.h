#include<bits/stdc++.h>
#include"tree_node.h"
using namespace std;

treeNode<int> * takeInput() {
	int data;
	cin >> data;
	treeNode<int> * root = new treeNode<int>(data);
	int numChild;
	cout << "Enter the Number of Children : ";
	cin >> numChild;
	for (int i = 0; i < numChild; i++) {
		root->children.push_back(takeInput());
	}
	return root;
}


void printTree(treeNode<int> * root) {
	if (!root)
		return ;
	cout << root->data << endl;
	for (int i = 0; i < root->children.size(); i++) {
		printTree(root->children[i]);
	}
}
