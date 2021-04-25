#include<bits/stdc++.h>
#include"linked_list.h"
using namespace std;

int findNode(Node<int> * head, int key) {
	Node<int> * temp = head;
	int index = 0;
	while (temp) {
		if (temp->data == key) {
			return index;
		}
		temp = temp->next;
		index++;
	}
	return -1;
}

int main() {
	Node<int> * head = takeInput();
	printLL(head);
	int key;
	cout << endl << "Enter the Key : ";
	cin >> key;
	int index = findNode(head, key);
	if (index == -1) {
		cout << "Node not Found" << endl;
		return 0;
	}
	cout << "Node found at position : " << index;
	return 0;
}
