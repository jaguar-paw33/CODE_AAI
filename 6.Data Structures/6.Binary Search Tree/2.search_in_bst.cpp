/*

Given a BST and an integer k. Find if the integer k is present in given BST or not. You have to return true, if node with data k is present, return false otherwise.

Note: Assume that BST contains all unique elements.

Input Format:
The first line of input contains data of the nodes of the tree in level order form. The data of the nodes of the tree is separated by space. If any node does not have left or right child, take -1 in its place. Since -1 is used as an indication whether the left or right nodes exist, therefore, it will not be a part of the data of any node.
The following line of input contains an integer, that denotes the value of k.

Output Format:
The first and only line of output contains a boolean value. Print true, if node with data k is present, print false otherwise.

Constraints:
Time Limit: 1 second

Sample Input 1 :
8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
2
Sample Output 1 :
true

Sample Input 2 :
8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
12
Sample Output 2 :
false

*/



#include<bits/stdc++.h>
#include"binary_search_tree.h"
using namespace std;

bool hasData(binaryTreeNode<int> * root, int data) {
	if (!root)
		return false;
	if (root->data == data)
		return true;
	else if (root->data > data) {
		return hasData(root->left, data);
	} else {
		return hasData(root->right, data);
	}
}

int main() {
	binaryTreeNode<int> * root = takeInput();
	int data;
	cin >> data;
	cout << (hasData(root, data) ? "true" : "false") << endl;
	delete root;
	return 0;
}



