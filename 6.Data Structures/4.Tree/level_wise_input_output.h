#include<bits/stdc++.h>
#include"tree_node.h"
using namespace std;

treeNode<int> * takeInput() {
	int rootData;
	cout << "Enter Root Data : ";
	cin >> rootData;
	treeNode<int> * root = new treeNode<int> (rootData);
	queue<treeNode<int>*> pending;
	pending.push(root);

	while (!pending.empty()) {
		treeNode<int> * temp = pending.front();
		pending.pop();
		int numChild;
		cout << "Enter the Number of Children of " << temp->data << " : ";
		cin >> numChild;
		int data;
		for (int i = 0; i < numChild; i++) {
			cout << "Enter Child " << i + 1 << " : ";
			cin >> data;
			treeNode<int> * child = new treeNode<int>(data);
			pending.push(child);
			temp->children.push_back(child);
		}
	}
	return root;
}

void printTree(treeNode<int> * root) {
	queue<treeNode<int>*> pending;
	pending.push(root);
	while (!pending.empty()) {
		treeNode<int> * temp = pending.front();
		pending.pop();
		cout << temp->data << " : ";
		for (int i = 0; i < temp->children.size(); i++) {
			pending.push(temp->children[i]);
			cout << temp->children[i]->data;
			if (i != temp->children.size() - 1)
				cout << ",";
		}
		cout << endl;
	}
}