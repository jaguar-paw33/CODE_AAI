/*

Given a binary tree, write code to create a separate linked list for each level. You need to return the array which contains head of each level linked list.

Input format :
The first line of input contains data of the nodes of the tree in level order form. The data of the nodes of the tree is separated by space. If any node does not have left or right child, take -1 in its place. Since -1 is used as an indication whether the left or right nodes exist, therefore, it will not be a part of the data of any node.

Output format :
Each level linked list is printed in new line (elements are separated by space).

Constraints:
Time Limit: 1 second

Sample Input 1:
5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1
Sample Output 1:
5
6 10
2 3
9

*/

#include<bits/stdc++.h>
#include"level_wise_input_output.h"
#include"linked_list.h"
using namespace std;

vector<Node<int> *> constructLinkedListForEachLevel(binaryTreeNode<int> * root) {
	vector<Node<int> *> ans;
	if (!root) {
		ans.push_back(NULL);
		return ans;
	}
	queue<binaryTreeNode<int>*> pending;
	pending.push(root);
	pending.push(NULL);
	Node<int> * head = NULL;
	Node<int> * tail = NULL;
	while (!pending.empty()) {
		binaryTreeNode<int> * temp = pending.front();
		pending.pop();

		if (temp->left)
			pending.push(temp->left);
		if (temp->right)
			pending.push(temp->right);

		Node<int> * newNode = new Node<int>(temp->data);

		if (!head) {
			head = newNode;
			tail = newNode;
		} else {
			tail->next = newNode;
			tail = newNode;
		}

		if (!pending.front()) {
			pending.pop();
			if (!pending.empty())
				pending.push(NULL);
			ans.push_back(head);
			head = NULL;
			tail = NULL;
		}
	}
	return ans;
}


int main() {
	binaryTreeNode<int> * root = takeInput();
	vector<Node<int>*> ans = constructLinkedListForEachLevel(root);
	for (int i = 0; i < ans.size(); i++) {
		cout << endl;
		printLL(ans[i]);
	}
	delete root;
	return 0;
}

