#include<bits/stdc++.h>
#include"singly_linked_list.h"
using namespace std;

Node * mid(Node * head) {
	Node * slow = head, * fast = head->next;

	while (fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
}

Node * merge(Node * h1, Node * h2) {
	Node * head = NULL, * tail = NULL;
	while (h1 && h2) {
		if (h1->data < h2->data) {
			if (!head) {
				head = h1;
				tail = h1;
			} else {
				tail->next = h1;
				tail = h1;
			}
			h1 = h1->next;
		} else {
			if (!head) {
				head = h2;
				tail = h2;
			} else {
				tail->next = h2;
				tail = h2;
			}
			h2 = h2->next;
		}
	}

	while (h1) {
		if (!head) {
			head = h1;
			tail = h1;
		} else {
			tail->next = h1;
			tail = h1;
		}
		h1 = h1->next;
	}

	while (h2) {
		if (!head) {
			head = h2;
			tail = h2;
		} else {
			tail->next = h2;
			tail = h2;
		}
		h2 = h2->next;
	}
	return head;
}

// Time Complexity - O(nlogn) and Space Complexity - O(logn) Stack Space
Node * mergeSort(Node * head) {
	if (!head || !head->next)
		return head;

	Node * mid_node = mid(head);
	Node * temp = mid_node->next;
	mid_node->next = NULL;

	head = mergeSort(head);
	temp = mergeSort(temp);

	head = merge(temp, head);

	return head;
}

int main() {
	int n;
	cin >> n;
	Node * head = takeInput(n);
	head = mergeSort(head);
	printLL(head);
	delete head;
	return 0;
}