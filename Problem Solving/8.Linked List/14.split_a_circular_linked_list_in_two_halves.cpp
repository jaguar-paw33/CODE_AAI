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
	tail->next = head; // Last Node Pointing to Head
	return head;
}

void printLL(Node * head) {
	if (!head)
		return;

	cout << head->data << " ";
	Node * temp = head->next;

	while (temp != head) {
		cout << temp->data << " ";
		temp = temp->next;
	}

	cout << endl;
}

pair<Node *, Node *> split_in_halves(Node * head) {
	Node * h1 = NULL, * h2 = NULL;

	if (!head) {
		return pair<Node * , Node *>(h1, h2);
	}

	Node * slow = head, * fast = head;

	bool begin = true;

	while (fast->next != head && fast->next->next != head) {
		begin = false;
		slow = slow->next;
		fast = fast->next->next;
	}

	h2 = slow->next;

	if (fast->next == head)
		fast->next = h2;
	else
		fast->next->next = h2;

	slow->next = head;
	h1 = head;

	if (h1 == h2) {
		h2 = NULL;
	}

	return pair<Node *, Node *>(h1, h2);

}

int main() {
	int n;
	cin >> n;
	Node * head = takeInput(n);
	pair<Node *, Node *> halves = split_in_halves(head);
	printLL(halves.first);
	printLL(halves.second);
	return 0;
}