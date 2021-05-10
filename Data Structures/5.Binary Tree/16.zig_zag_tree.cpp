/*

Given a binary tree, print the zig zag order. In zigzag order, level 1 is printed from left to right, level 2 from right to left and so on. This means odd levels should get printed from left to right and even level right to left.

Input format:
The first line of input contains data of the nodes of the tree in level order form. The data of the nodes of the tree is separated by space. If any node does not have a left or right child, take -1 in its place. Since -1 is used as an indication whether the left or right nodes exist, therefore, it will not be a part of the data of any node.

Output Format:
The binary tree is printed level wise, as described in the task. Each level is printed in new line.

Constraints
Time Limit: 1 second

Sample Input :
5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1
Sample Output :
5
10 6
2 3
9

*/

#include<bits/stdc++.h>
#include"level_wise_input_output.h"
using namespace std;

void printZigZag(binaryTreeNode<int> * root) {
	if (!root)
		return;
	stack<binaryTreeNode<int>*> lr;
	stack<binaryTreeNode<int>*> rl;
	lr.push(root);
	while (!lr.empty() || !rl.empty()) {
		while (!lr.empty()) {
			binaryTreeNode<int> * temp = lr.top();
			lr.pop();
			cout << temp->data << " ";
			if (temp->left)
				rl.push(temp->left);
			if (temp->right)
				rl.push(temp->right);
			if (lr.empty())
				cout << endl;
		}
		while (!rl.empty()) {
			binaryTreeNode<int> * temp = rl.top();
			rl.pop();
			cout << temp->data << " ";
			if (temp->right)
				lr.push(temp->right);
			if (temp->left)
				lr.push(temp->left);
			if (rl.empty())
				cout << endl;
		}
	}
}

int main() {
	binaryTreeNode<int> * root = takeInput();
	printZigZag(root);
	delete root;
	return 0;
}