/*

For a given a Binary Tree of type integer, print it in a level order fashion where each level will be printed on a new line. Elements on every level will be printed in a linear fashion and a single space will separate them.

Input Format:
The first and the only line of input will contain the node data, all separated by a single space. Since -1 is used as an indication whether the left or right node data exist for root, it will not be a part of the node data.

Output Format:
The given input tree will be printed in a level order fashion where each level will be printed on a new line.
Elements on every level will be printed in a linear fashion. A single space will separate them.

Constraints:
1 <= N <= 10^5
Where N is the total number of nodes in the binary tree.

Time Limit: 1 sec

Sample Input 1:
10 20 30 40 50 -1 60 -1 -1 -1 -1 -1 -1
Sample Output 1:
10
20 30
40 50 60

Sample Input 2:
8 3 10 1 6 -1 14 -1 -1 4 7 13 -1 -1 -1 -1 -1 -1 -1`
Sample Output 2:
8
3 10
1 6 14
4 7 13

*/

#include<bits/stdc++.h>
#include"level_wise_input_output.h"
using namespace std;

void printFormatted(binaryTreeNode<int> * root) {
	if (!root)
		return;
	queue<binaryTreeNode<int> *> pending;
	pending.push(root);
	pending.push(NULL);
	while (!pending.empty()) {
		binaryTreeNode<int> * temp = pending.front();
		pending.pop();
		cout << temp->data << " ";
		if (temp->left)
			pending.push(temp->left);
		if (temp->right)
			pending.push(temp->right);
		if (!pending.front()) {
			pending.pop();
			cout << endl;
			if (!pending.empty())
				pending.push(NULL);
		}
	}
}

int main() {
	binaryTreeNode<int> * root = takeInput();
	printFormatted(root);
	delete root;
	return 0;
}