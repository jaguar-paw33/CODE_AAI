/*

For a given preorder and inorder traversal of a Binary Tree of type integer stored in an array/list, create the binary tree using the given two arrays/lists. You just need to construct the tree and return the root.

Note:
Assume that the Binary Tree contains only unique elements.

Input Format:
The first line of input contains an integer N denoting the size of the list/array. It can also be said that N is the total number of nodes the binary tree would have.

The second line of input contains N integers, all separated by a single space. It represents the preorder-traversal of the binary tree.

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
1 2 4 5 3 6 7
4 2 5 1 6 3 7
Sample Output 1:
1
2 3
4 5 6 7

Sample Input 2:
6
5 6 2 3 9 10
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

binaryTreeNode<int> * construct(int * inorder, int is, int ie, int * preorder, int ps, int pe) {
	if (is > ie || ps > pe) {
		return NULL;
	}
	binaryTreeNode<int> * root = new binaryTreeNode<int>(preorder[ps]);
	int i;
	for (i = is; inorder[i] != root->data; i++) {}
	int lis = is;
	int lie = i - 1;
	int lps = ps + 1;
	int ris = i + 1;
	int rie = ie;
	int rpe = pe;
	int lpe = lie - lis + lps;
	int rps = lpe + 1;
	root->left = construct(inorder, lis, lie, preorder, lps, lpe);
	root->right = construct(inorder, ris, rie, preorder, rps, rpe);
	return root;
}

binaryTreeNode<int> * construct_tree(int * inorder, int inLength, int * preorder, int preLength) {
	return construct(inorder, 0, inLength - 1, preorder, 0, preLength - 1);
}

int main() {
	int length;
	cin >> length;
	int * preorder = new int [length];
	for (int i = 0; i < length; i++) {
		cin >> preorder[i];
	}

	int * inorder = new int [length];
	for (int i = 0; i < length; i++) {
		cin >> inorder[i];
	}
	binaryTreeNode<int> * root = construct_tree(inorder, length, preorder, length);
	printBinaryTree(root);
	delete [] inorder;
	delete [] preorder;
	return 0;
}