#include<bits/stdc++.h>
#include"node_class.h"
using namespace std;

// Indexing of a Linked List is same as that of an Array

Node<int> * takeInput() {

	Node<int> * head = NULL;
	Node<int> * tail = NULL;

	int data;
	cin >> data;

	// Considering -1 as the end of the input
	while (data != -1) {
		Node<int> * newNode = new Node<int>(data);

		if (!head) {
			head = newNode;
			tail = newNode;
		} else {
			tail->next = newNode;
			tail = newNode;
		}
		cin >> data;
	}

	return head;
}


void printLL(Node<int> * head) {
	Node<int> * temp = head;

	while (temp) {
		cout << temp->data << " ";
		temp = temp->next;
	}
}