/*

Given a BST, convert it into a sorted linked list. You have to return the head of LL.

Input format:
The first and only line of input contains data of the nodes of the tree in level order form. The data of the nodes of the tree is separated by space. If any node does not have left or right child, take -1 in its place. Since -1 is used as an indication whether the left or right nodes exist, therefore, it will not be a part of the data of any node.

Output Format:
The first and only line of output prints the elements of sorted linked list.

Constraints:
Time Limit: 1 second

Sample Input 1:
8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
Sample Output 1:
2 5 6 7 8 10

*/

#include<bits/stdc++.h>
#include"linked_list.h"
#include"binary_search_tree.h"
using namespace std;

pair<Node<int>*, Node<int>*> BSTtoSortedLL(binaryTreeNode<int> * root) {

	// first - head
	// second - tail

	if (!root)
	{
		pair<Node<int>*, Node<int>*> p(NULL, NULL);
		return p;
	}
	Node<int> * newNode = new Node<int>(root->data);
	pair < Node<int>*, Node<int>*> l = BSTtoSortedLL(root->left);
	pair < Node<int>*, Node<int>*> r = BSTtoSortedLL(root->right);
	pair<Node<int>*, Node<int>*> ans;
	if (!l.first && !r.first) {
		ans.first = newNode;
		ans.second = newNode;
	}
	else if (!l.first) {
		newNode->next = r.first;
		ans.first = newNode;
		ans.second = r.second;
	} else if (!r.first) {
		l.second->next = newNode;
		ans.first = l.first;
		ans.second = newNode;
	} else {
		l.second->next = newNode;
		newNode->next = r.first;
		ans.first = l.first;
		ans.second = r.second;
	}
	return ans;
}

int main() {
	binaryTreeNode<int> * root = takeInput();
	Node<int> * head = BSTtoSortedLL(root).first;
	printLL(head);
	delete root;
	delete head;
	return 0;
}