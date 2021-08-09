#include<bits/stdc++.h>
#include"singly_linked_list.h"
using namespace std;

int reverse_and_get_length(Node ** head) {
	Node * prev = NULL, * cur = *head;
	int len = 0;
	while (cur) {
		Node * temp = cur->next;
		cur->next = prev;
		prev = cur;
		cur = temp;
		len++;
	}
	* head = prev;
	return len;
}

// The resultant product can either have M+N digits or M+N-1 digits where M and N are the digits in both the numbers respectively
Node * makeEmptyList(int n) {
	Node * h = NULL;
	while (n--) {
		Node * newNode = new Node(0);
		if (!h) {
			h = newNode;
		} else {
			newNode->next = h;
			h = newNode;
		}
	}
	return h;
}

Node * multiply(Node * h1, Node * h2) {

	int m = reverse_and_get_length(&h1);
	int n = reverse_and_get_length(&h2);

	Node * h = makeEmptyList(m + n);

	Node * t1 = h1, * result = h, * t2, *cur;

	while (t1) {

		int p, r = 0;
		int d = t1->data;
		t2 = h2;
		cur = result;

		while (t2) {
			p = t2->data * d + r;
			cur->data += p;
			r = cur->data / 10;
			cur->data %= 10;
			t2 = t2->next;
			cur = cur->next;
		}

		if (r) {
			cur->data += r;
		}

		t1 = t1->next;
		result = result->next;
	}

	reverse_and_get_length(&h);
	reverse_and_get_length(&h1);
	reverse_and_get_length(&h2);

	while (h && h->next && !h->data) {
		h = h->next;
	}

	return h;
}

int main() {
	int n1, n2;
	cin >> n1 >> n2;

	Node * h1 = takeInput(n1);
	Node * h2 = takeInput(n2);

	Node * h = multiply(h1, h2);
	printLL(h);

	delete h1, h2, h;

	return 0;
}