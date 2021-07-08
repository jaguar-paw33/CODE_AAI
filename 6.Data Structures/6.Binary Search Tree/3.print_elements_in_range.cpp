/*

Given a Binary Search Tree and two integers k1 and k2, find and print the elements which are in range k1 and k2 (both inclusive).

Print the elements in increasing order.

Input format:
The first line of input contains data of the nodes of the tree in level order form. The data of the nodes of the tree is separated by space. If any node does not have left or right child, take -1 in its place. Since -1 is used as an indication whether the left or right nodes exist, therefore, it will not be a part of the data of any node.
The following line contains two integers, that denote the value of k1 and k2.

Output Format:
The first and only line of output prints the elements which are in range k1 and k2 (both inclusive). Print the elements in increasing order.

Constraints:
Time Limit: 1 second

Sample Input 1:
8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
6 10
Sample Output 1:
6 7 8 10

*/

#include<bits/stdc++.h>
#include"binary_search_tree.h"
using namespace std;

void print_elements_in_range_k1_k2(binaryTreeNode<int> * root, int k1, int k2) {
	if (!root)
		return;
	if (root->data > k2) {
		print_elements_in_range_k1_k2(root->left, k1, k2);
	} else if (root->data < k1) {
		print_elements_in_range_k1_k2(root->right, k1, k2);
	} else {
		print_elements_in_range_k1_k2(root->left, k1, k2);
		cout << root->data << " ";
		print_elements_in_range_k1_k2(root->right, k1, k2);
	}
}

int main() {
	binaryTreeNode<int> * root = takeInput();
	int k1, k2;
	cin >> k1 >> k2;
	print_elements_in_range_k1_k2(root, k1, k2);
	delete root;
	return 0;
}