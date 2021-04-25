#include<bits/stdc++.h>
#include"linked_list.h"
using namespace std;

Node<int> * insertNode(Node<int> * head, int i, int data) {
	if (!i) {
		Node<int> * newNode = new Node<int> (data);
		newNode->next = head;
		return newNode;
	} else if (!head) {
		return head;
	}

	Node<int> * temp = insertNode(head->next, i - 1, data);
	head->next = temp;
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
