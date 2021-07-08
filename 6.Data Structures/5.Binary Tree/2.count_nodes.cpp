#include<bits/stdc++.h>
#include"level_wise_input_output.h"
using namespace std;

int nodes_count(binaryTreeNode<int> * root) {
	if (!root)
		return 0;
	return 1 + nodes_count(root->left) + nodes_count(root->right);
}

int main() {
	binaryTreeNode<int> * root = takeInput();
	cout << nodes_count(root) << endl;
	return 0;
}