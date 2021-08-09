/*

You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.

*/


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

Node * takeInput() {
	Node * head = NULL, *tail = NULL;

	int data;
	cin >> data;

	while (data != -1) {
		Node * newNode = new Node(data);
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


void print(Node * head) {
	Node * temp = head;
	while (temp) {
		cout << temp->data << " ";
		temp = temp->next;
	}
}

Node * compute_sum(Node * head1, Node * head2) {
	Node * fh = NULL, * ft = NULL;

	Node * t1 = head1, * t2 = head2;
	int rem = 0;

	while (t1 && t2) {
		Node * newNode = new Node((t1->data + t2->data + rem) % 10);
		rem = (t1->data + t2->data + rem) / 10;

		if (!fh) {
			fh = newNode;
			ft = newNode;
		} else {
			ft->next = newNode;
			ft = newNode;
		}

		t1 = t1->next;
		t2 = t2->next;
	}

	while (t1) {
		if (!fh)
			return t1;

		Node * newNode = new Node((t1->data + rem) % 10);
		rem = (t1->data + rem) / 10;

		ft->next = newNode;
		ft = newNode;
		t1 = t1->next;
	}

	while (t2) {
		if (!fh)
			return t2;

		Node * newNode = new Node((t2->data + rem) % 10);
		rem = (t2->data + rem) / 10;

		ft->next = newNode;
		ft = newNode;
		t2 = t2->next;
	}

	if (rem) {
		Node * newNode = new Node(rem);
		ft->next = newNode;
		ft = newNode;
	}

	return fh;
}

int main() {
	Node * head1 = takeInput();
	Node * head2 = takeInput();

	Node * sum = compute_sum(head1, head2);

	print(sum);

	delete head1, head2, sum;

	return 0;
}
