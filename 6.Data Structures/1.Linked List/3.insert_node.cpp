#include<bits/stdc++.h>
#include"linked_list.h"
using namespace std;

Node<int> * insertNode(Node<int> * head, int i, int data) {
	if (!head)
		return head;
	Node<int> * prev = NULL;
	Node<int> * cur = head;
	Node<int> * newNode =  new Node<int>(data);

	while (i-- && cur) {
		prev = cur;
		cur = cur->next;
	}

	if (!prev) {
		newNode->next = head;
		head = newNode;
	} else if (i == -1) {
		if (!cur) {
			prev->next = newNode;
		} else {
			prev->next = newNode;
			newNode->next = cur;
		}
	}
	return head;
}

int main() {
	Node<int> * head = takeInput();
	printLL(head);
	int i;
	cout << endl << "Enter the Position : ";
	cin >> i;
	int data;
	cout << "Enter the Node Data : ";
	cin >> data;
	head = insertNode(head, i, data);
	cout << endl << "Updated Linked List : ";
	printLL(head);
	return 0;
}
