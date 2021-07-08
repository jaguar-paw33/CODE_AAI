/*

Given the binary Tree and two nodes say ‘p’ and ‘q’. Determine whether the two nodes are cousins of each other or not. Two nodes are said to be cousins of each other if they are at same level of the Binary Tree and have different parents.

Do it in O(n).

Input format :
Line 1 : Nodes in level order form (separated by space). If any node does not have left or right child, take -1 in its place
Line 2 : integer value of p
Line 3 : Integer value of q

Output format :
true or false

Constraints :
1 <= N <= 10^5

Sample Input :
5 6 10 2 3 4 -1 -1 -1 -1 9 -1 -1 -1 -1
2
4
Sample Output :
true

*/

#include<bits/stdc++.h>
#include"level_wise_input_output.h"
using namespace std;


pair<int, binaryTreeNode<int>*> helper(binaryTreeNode<int>* root, int node_data) {
	if (!root || root->data == node_data) {
		pair<int, binaryTreeNode<int>*> p(-1, NULL);
		return p;
	}
	pair<int, binaryTreeNode<int>*> p(-1, NULL);
	if ((root->left && root->left->data == node_data) || (root->right && root->right->data == node_data)) {
		p.first = 0;
		p.second = root;
		return p;
	}
	p = helper(root->left, node_data);
	if (p.first != -1) {
		p.first += 1;
		return p;
	}
	p = helper(root->right, node_data);
	if (p.first != -1) {
		p.first += 1;
	}
	return p;
}



bool isCousin(binaryTreeNode<int> * root, int node1_data, int node2_data) {
	pair<int, binaryTreeNode<int>*> l = helper(root, node1_data);
	pair<int, binaryTreeNode<int>*> r = helper(root, node2_data);
	if (l.first == r.first && l.second != r.second)
		return true;
	return false;
}

int main() {
	binaryTreeNode<int> * root = takeInput();
	int node1_data, node2_data;
	cin >> node1_data >> node2_data;
	cout << (isCousin(root, node1_data, node2_data) ? "true" : "false") << endl;
	delete root;
	return 0;
}