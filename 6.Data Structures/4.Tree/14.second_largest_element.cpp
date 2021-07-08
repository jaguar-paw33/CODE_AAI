/*

Given a generic tree, find and return the node with second largest value in given tree.

Note: Return NULL if no node with required value is present.

Input format :
The first line of input contains data of the nodes of the tree in level order form. The order is: data for root node, number of children to root node, data of each of child nodes and so on and so forth for each node. The data of the nodes of the tree is separated by space.

Output Format :
The first and only line of output contains data of the node with second largest data.

Constraints:
Time Limit: 1 sec

Sample Input 1 :
10 3 20 30 40 2 40 50 0 0 0 0
Sample Output 1 :
40

*/


#include<bits/stdc++.h>
#include"level_wise_input_output.h"
using namespace std;

pair<treeNode<int> * , treeNode<int> *> second_largest(treeNode<int> * root) {
	if (!root) {
		pair<treeNode<int>*, treeNode<int>*> p;
		p.first = NULL;
		p.second = NULL;
		return p;
	}
	pair<treeNode<int>*, treeNode<int>*> ans;
	ans.first = root;
	ans.second = NULL;
	for (int i = 0; i < root->children.size(); i++) {
		pair<treeNode<int>*, treeNode<int>*> p = second_largest(root->children[i]);
		if (p.first && p.first->data > ans.first->data) {
			if (p.second && p.second->data > ans.first->data) {
				ans.second = p.second;
				ans.first = p.first;
			} else {
				ans.second = ans.first;
				ans.first = p.first;
			}
		} else if (p.first && ans.second && p.first->data > ans.second->data) {
			ans.second = p.first;
		}
	}
	return ans;
}

int main() {
	treeNode<int> * root = takeInput();
	pair <treeNode<int>*, treeNode<int> *>ans = second_largest(root);
	if (!ans.first)
		cout << "No Node is Present" << endl;
	else
		cout << ans.second->data << endl;
	return 0;
}