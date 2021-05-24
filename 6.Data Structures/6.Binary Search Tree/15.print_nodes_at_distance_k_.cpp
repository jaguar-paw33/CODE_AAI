/*

You are given a Binary Tree of type integer, a target node, and an integer value K.
Print the data of all nodes that have a distance K from the target node. The order in which they would be printed will not matter.

Input Format:
The first line of input will contain the node data, all separated by a single space. Since -1 is used as an indication whether the left or right node data exist for root, it will not be a part of the node data.

The second line of input contains two integers separated by a single space, representing the value of the target node and K, respectively.

Output Format:
All the node data at distance K from the target node will be printed on a new line.

The order in which the data is printed doesn't matter.

Constraints:
1 <= N <= 10^5
Where N is the total number of nodes in the binary tree.

Time Limit: 1 sec

Sample Input 1:
5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1
3 1
Sample Output 1:
9
6

Sample Input 2:
1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1
3 3
Sample Output 2:
4
5

*/

#include<bits/stdc++.h>
#include"level_wise_input_output.h"
using namespace std;

void print_nodes_at_depth_k(binaryTreeNode<int> * root, int k) {
	if (!root)
		return;
	if (!k) {
		cout << root->data << endl;
		return;
	}
	print_nodes_at_depth_k(root->left, k - 1);
	print_nodes_at_depth_k(root->right, k - 1);
}

int helper(binaryTreeNode<int>* root, int node_data, int k) {
	if (!root)
		return -1;
	if (root->data == node_data) {
		print_nodes_at_depth_k(root, k);
		return 0;
	}
	int l = helper(root->left, node_data, k);
	int r = helper(root->right, node_data, k);
	if (l == -1 && r == -1) {
		return -1;
	}
	if (l != -1 && k >= l + 2) {
		print_nodes_at_depth_k(root->right, k - l - 2);
	} else if (l != -1 && k == l + 1) {
		cout << root->data << endl;
	}
	if (r != -1 && k >= r + 2) {
		print_nodes_at_depth_k(root->left, k - r - 2);
	} else if (r != -1 && k == r + 1) {
		cout << root->data << endl;
	}
	return l == -1 ? r + 1 : l + 1;
}

void nodes_at_distance_k_from_node(binaryTreeNode<int>* root, int node, int k) {
	helper(root, node, k);
}

int main() {
	binaryTreeNode<int> * root = takeInput();
	int node_data;
	cin >> node_data;
	int k;
	cin >> k;
	nodes_at_distance_k_from_node(root, node_data, k);
	delete root;
	return 0;
}