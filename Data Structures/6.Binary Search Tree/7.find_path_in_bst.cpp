/*

Given a BST and an integer k. Find and return the path from the node with data k and root (if a node with data k is present in given BST) in a list. Return empty list otherwise.

Note: Assume that BST contains all unique elements.

Input Format :
The first line of input contains data of the nodes of the tree in level order form. The data of the nodes of the tree is separated by space. If any node does not have left or right child, take -1 in its place. Since -1 is used as an indication whether the left or right nodes exist, therefore, it will not be a part of the data of any node.
The following line of input contains an integer, that denotes the value of k.

Output Format :
The first line and only line of output prints the data of the nodes in the path from node k to root. The data of the nodes is separated by single space.

Constraints:
Time Limit: 1 second

Sample Input 1:
8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
2
Sample Output 1:
2 5 8

*/


#include<bits/stdc++.h>
#include"binary_search_tree.h"
using namespace std;

// Using Doubly Ended Linked List
list<int> * path_from_node_to_root_using_list(binaryTreeNode<int> * root, int node_data) {
	if (!root) {
		return NULL;
	}
	if (root->data == node_data) {
		list<int> * ans = new list<int>;
		ans->push_back(root->data);
		return ans;
	}
	list<int> * ans = NULL;
	if (root->data > node_data) {
		ans = path_from_node_to_root_using_list(root->left, node_data);
	} else if (root->data < node_data) {
		ans = path_from_node_to_root_using_list(root->right, node_data);
	}
	if (ans)
		ans->push_back(root->data);
	return ans;
}

//Using Vector
vector<int> * path_from_node_to_root_using_vector(binaryTreeNode<int> * root, int node_data) {
	if (!root) {
		return NULL;
	}
	if (root->data == node_data) {
		vector<int> * ans = new vector<int>;
		ans->push_back(root->data);
		return ans;
	}
	vector<int> * ans = NULL;
	if (root->data > node_data) {
		ans = path_from_node_to_root_using_vector(root->left, node_data);
	} else if (root->data < node_data) {
		ans = path_from_node_to_root_using_vector(root->right, node_data);
	}
	if (ans)
		ans->push_back(root->data);
	return ans;
}


int main() {
	binaryTreeNode<int> * root = takeInput();
	int node_data;
	cin >> node_data;
	list<int> * l;
	vector<int> * v;
	l = path_from_node_to_root_using_list(root, node_data);
	v = path_from_node_to_root_using_vector(root, node_data);
	list<int>::iterator lit;
	for (lit = l->begin(); lit != l->end(); lit++) {
		cout << *lit << " ";
	}
	cout << endl;
	for (int i = 0; i < v->size(); i++) {
		cout << (*v)[i] << " ";
	}
	delete root;
	delete l;
	delete v;
	return 0;
}