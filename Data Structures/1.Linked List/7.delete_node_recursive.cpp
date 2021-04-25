#include<bits/stdc++.h>
#include"linked_list.h"
using namespace std;

Node<int> * delNode(Node<int> * head, int i) {
	if (!head) {
		return head;
	}
	else if (!i) {
		Node<int> * temp = head;
		head = head->next;
		temp->next = NULL;
		delete temp;
		return head;
	}

	Node<int> * temp = delNode(head->next, i - 1);
	head->next = temp;
	return head;
}

int main() {
	Node<int> * head = takeInput();
	printLL(head);
	int i;
	cout << endl << "Enter the Position : ";
	cin >> i;
	head = delNode(head, i);
	cout << endl << "Updated Linked List : ";
	printLL(head);
	return 0;
}
