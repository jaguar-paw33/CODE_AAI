#include<bits/stdc++.h>
#include"singly_linked_list.h"
using namespace std;

Node * reverse(Node * head) {
	Node * prev = NULL, * cur = head;

	while (cur) {
		Node * temp = cur->next;
		cur->next = prev;
		prev = cur;
		cur = temp;
	}

	return prev;
}

Node * reverse_alternate_K(Node * head, int K) {

	Node * nh = NULL;

	Node * prev = head, * cur = head, *h = NULL, * t1 = NULL, * t2 = NULL;

	int num_nodes;

	while (cur) {

		h = cur;

		num_nodes = K;

		while (cur && num_nodes--) {
			prev = cur;
			cur = cur->next;
		}

		prev->next = NULL;
		t1 = reverse(h);
		h->next = cur;

		if (t2) {
			t2->next = t1;
		}

		if (!nh) {
			nh = t1;
		}

		num_nodes = K;

		while (cur && num_nodes--) {
			prev = cur;
			cur = cur->next;
		}

		t2 = prev;
	}
	return nh;
}

int main() {
	int n;
	cin >> n;

	Node * head = takeInput(n);

	int K;
	cin >> K;

	printLL(head);

	head = reverse_alternate_K(head, K);

	printLL(head);

	delete head;

	return 0;
}