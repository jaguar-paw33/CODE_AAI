/*

For a given Binary Tree of type integer, print all the nodes without any siblings.

Input Format:
The first and the only line of input will contain the node data, all separated by a single space. Since -1 is used as an indication whether the left or right node data exist for root, it will not be a part of the node data.

Output Format:
The only line of output prints the node data in a top to down fashion with reference to the root.
Node data in the left subtree will be printed first and then the right subtree.
A single space will separate them all.

Constraints:
1 <= N <= 10^5
Where N is the total number of nodes in the binary tree.

Time Limit: 1 second

Sample Input 1:
5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1
Sample Output 1:
9

Sample Input 2:
2 4 5 6 -1 -1 7 20 30 80 90 -1 8 9 -1 -1 -1 -1 -1 -1 -1 -1 -1
Sample Output 2:
6 8 9 7
Explanation of Sample Input 2:

*/

#include<bits/stdc++.h>
#include"level_wise_input_output.h"
using namespace std;

void nodes_without_sibling(binaryTreeNode<int> * root) {
	if (!root)
		return;
	if (root->left && !root->right)
		cout << root->left->data << " ";
	if (root->right && !root->left)
		cout << root->right->data << " ";
	nodes_without_sibling(root->left);
	nodes_without_sibling(root->right);
}

int main() {
	binaryTreeNode<int> * root = takeInput();
	nodes_without_sibling(root);
	delete root;
	return 0;
}