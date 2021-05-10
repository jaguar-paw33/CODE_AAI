#include<bits/stdc++.h>
#include"binary_search_tree.h"
using namespace std;

int main() {

	binaryTreeNode<int> * root = takeInput();
	printTree(root);
	root = deleteNode(root, 10);
	printTree(root);
	delete root;
	return 0;
}