/*

A space efficient Doubly Linked List using one pointer only in each node as opposed to general doubly linked list with two pointers (previous and next).

*/

#include<bits/stdc++.h>
using namespace std;

// XOR Doubly Linked List Class
class Node {
public:
	int data;
	Node * next;

	Node(int data) {
		this->data = data;
		next = NULL;
	}

	~Node() {
		delete next;
	}
};

Node * XOR(Node * a, Node * b) {
	return (Node *) (uintptr_t(a)^uintptr_t(b));
}

Node * takeInput(int n) {
	int data;

	Node * head = NULL, * tail = NULL;

	while (n--) {
		cin >> data;
		Node * newNode = new Node(data);

		if (!head) {
			head = newNode;
			tail = newNode;
		} else {
			tail->next = newNode;
			tail = newNode;
		}
	}

	Node * prev = NULL, *cur = head;

	while (cur) {
		cur->next = XOR(prev, cur->next);
		Node * temp = prev;
		prev = cur;
		cur = XOR(temp, cur->next);
	}

	return head;
}

void printLL_forward(Node * head) {
	Node * prev = NULL, * cur = head;
	while (cur) {
		cout << cur->data << " ";
		Node * temp = prev;
		prev = cur;
		cur = XOR(temp, cur->next);
	}
}

void printLL_backward(Node * head) {
	Node * prev = NULL, * cur = head;
	while (cur) {
		Node * temp = prev;
		prev = cur;
		cur = XOR(temp, cur->next);
	}

	cout << endl;

	cur = prev;
	Node * next = NULL;

	while (cur) {
		cout << cur->data << " ";
		Node * temp = next;
		next = cur;
		cur = XOR(temp, cur->next);
	}
}

int main() {
	int n;
	cin >> n;
	Node * head = takeInput(n);
	printLL_forward(head);
	printLL_backward(head);
	return 0;
}



