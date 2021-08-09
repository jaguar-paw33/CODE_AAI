#include<bits/stdc++.h>
using namespace std;

class Node {
public:
	int data;
	Node * next;

	Node(int data) {
		this->data = data;
		this->next = NULL;
	}

	~Node() {
		delete next;
	}
};

Node * takeInput(int n) {
	int data;

	Node * head = NULL, *tail = NULL;

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
	return head;
}

void printLL(Node * head) {
	Node * temp = head;
	while (temp) {
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}
