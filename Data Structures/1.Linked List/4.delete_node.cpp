#include<bits/stdc++.h>
#include"linked_list.h"
using namespace std;

Node<int> * delNode(Node<int> * head, int i) {
	if (!head)
		return NULL;

	Node<int> * prev = NULL;
	Node<int> * cur = head;

	while (i-- && cur)
	{
		prev = cur;
		cur = cur->next;
	}
	if (!prev)
	{
		cur = cur->next;
		head->next = NULL;
		delete head;
		head = cur;
	} else {
		if (!cur)
			return head;
		else {
			prev->next = cur->next;
			cur->next = NULL;
			delete cur;
		}
	}
	return head;
}

int main() {
	Node<int> * head = takeInput();
	printLL(head);
	cout << endl << "Enter the value of i : ";
	int i;
	cin >> i;
	head = delNode(head, i);
	cout << endl << "Updated Linked List : ";
	printLL(head);
	return 0;
}
