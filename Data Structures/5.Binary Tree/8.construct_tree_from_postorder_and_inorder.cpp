/*

For a given postorder and inorder traversal of a Binary Tree of type integer stored in an array/list, create the binary tree using the given two arrays/lists. You just need to construct the tree and return the root.

Note:
Assume that the Binary Tree contains only unique elements.

Input Format:
The first line of input contains an integer N denoting the size of the list/array. It can also be said that N is the total number of nodes the binary tree would have.

The second line of input contains N integers, all separated by a single space. It represents the Postorder-traversal of the binary tree.

The third line of input contains N integers, all separated by a single space. It represents the inorder-traversal of the binary tree.

Output Format:
The given input tree will be printed in a level order fashion where each level will be printed on a new line.
Elements on every level will be printed in a linear fashion. A single space will separate them.

Constraints:
1 <= N <= 10^4
Where N is the total number of nodes in the binary tree.

Time Limit: 1 sec

Sample Input 1:
7
4 5 2 6 7 3 1
4 2 5 1 6 3 7
Sample Output 1:
1
2 3
4 5 6 7

Sample Input 2:
6
2 9 3 6 10 5
2 6 3 9 5 10
Sample Output 2:
5
6 10
2 3
9

*/


#include<bits/stdc++.h>
#include"level_wise_input_output.h"
using namespace std;

binaryTreeNode<int> * construct(int * inorder, int is, int ie, int * postorder, int ps, int pe) {
	if (is > ie || ps > pe) {
		return NULL;
	}
	binaryTreeNode<int> * root = new binaryTreeNode<int>(postorder[pe]);
	int i;
	for (i = is; inorder[i] != root->data; i++) {}
	int lis = is;
	int lie = i - 1;
	int lps = ps;
	int ris = i + 1;
	int rie = ie;
	int rpe = pe - 1;
	int lpe = lie - lis + lps;
	int rps = lpe + 1;
	root->left = construct(inorder, lis, lie, postorder, lps, lpe);
	root->right = construct(inorder, ris, rie, postorder, rps, rpe);
	return root;
}

binaryTreeNode<int> * construct_tree(int * inorder, int inLength, int * postorder, int postLength) {
	return construct(inorder, 0, inLength - 1, postorder, 0, postLength - 1);
}

int main() {
	int length;
	cin >> length;
	int * postorder = new int [length];
	for (int i = 0; i < length; i++) {
		cin >> postorder[i];
	}

	int * inorder = new int [length];
	for (int i = 0; i < length; i++) {
		cin >> inorder[i];
	}
	binaryTreeNode<int> * root = construct_tree(inorder, length, postorder, length);
	printBinaryTree(root);
	delete [] inorder;
	delete [] postorder;
	return 0;
}