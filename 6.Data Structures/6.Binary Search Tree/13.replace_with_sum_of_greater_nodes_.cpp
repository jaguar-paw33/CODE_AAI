/*

Given a binary search tree, you have to replace each node's data with the sum of all nodes which are greater or equal than it. You need to include the current node's data also.
That is, if in given BST there is a node with data 5, you need to replace it with sum of its data (i.e. 5) and all nodes whose data is greater than or equal to 5.

Note: You don't need to return or print, just change the data of each node.

Input format:
The first line of input contains data of the nodes of the tree in level order form. The data of the nodes of the tree is separated by space. If any node does not have left or right child, take -1 in its place. Since -1 is used as an indication whether the left or right nodes exist, therefore, it will not be a part of the data of any node.

Output format:
In the output, data of the nodes of the tree are printed in level order form. Each level of the tree is printed on a separate line.

Constraints:
Time Limit: 1 second

Sample Input 1 :
8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
Sample Output 1 :
18
36 10
38 31
25

*/

#include<bits/stdc++.h>
#include"binary_search_tree.h"
using namespace std;

void sum_greater_nodes(binaryTreeNode<int> * root, int & s) {
	if (!root)
		return;
	sum_greater_nodes(root->right, s);
	root->data += s;
	s = root->data;
	sum_greater_nodes(root->left, s);
}

int main() {
	binaryTreeNode<int> * root = takeInput();
	int s = 0;
	sum_greater_nodes(root, s);
	printTree(root);
	delete root;
	return 0;
}