/*

Given a binary tree, return the longest path from leaf to root. Longest means, a path which contain maximum number of nodes from leaf to root.

Input format :
Elements in level order form (separated by space)

(If any node does not have left or right child, take -1 in its place)

Line 1 : Binary Tree 1 (separated by space)

Sample Input 1 :
5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1
Sample Output 1 :
9
3
6
5

*/

#include<bits/stdc++.h>
#include"level_wise_input_output.h"
using namespace std;

vector<int> * longest_leaf_to_root_path(binaryTreeNode<int> * root) {
	if (!root) {
		vector<int> * ans = new vector<int>;
		return ans;
	}
	vector<int> * l = longest_leaf_to_root_path(root->left);
	vector<int> * r = longest_leaf_to_root_path(root->right);
	vector<int> * ans = l->size() > r->size() ? l : r;
	ans->push_back(root->data);
	return ans;
}

int main() {
	binaryTreeNode<int> * root = takeInput();
	vector<int> * v = longest_leaf_to_root_path(root);
	for (int i = 0; i < v->size(); i++) {
		cout << v->at(i) << " ";
	}
	delete root;
	return 0;
}