#include<bits/stdc++.h>
#include"linked_list.h"
using namespace std;

Node<int> * ithNode(Node<int> * head, int i) {
	if (!head)
		return NULL;

	Node<int> * temp = head;

	while (i-- && temp)
	{
		temp = temp->next;
	}
	return temp;
}

int main() {
	Node<int> * head = takeInput();
	printLL(head);
	cout << endl << "Enter the value of i : ";
	int i;
	cin >> i;
	Node<int> * node = ithNode(head, i);
	cout << endl << "Node " << i << " : " << ((node == NULL) ? -1 : node->data) << endl;
	return 0;
}
