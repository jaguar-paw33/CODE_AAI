/*

Merge two sorted linked lists and return it as a sorted list. The list should be made by splicing together the nodes of the first two lists.

Input: l1 = [1,2,4], l2 = [1,3,4]
Output: [1,1,2,3,4,4]

*/

#include<bits/stdc++.h>
using namespace std;

class ListNode {
public:
	int val;
	ListNode * next;

	ListNode(int val) {
		this->val = val;
		this->next = NULL;
	}
};

ListNode * takeInput() {
	int val;
	cin >> val;

	ListNode * head = NULL, * tail = NULL;


	while (val != -1) {
		ListNode * newNode = new ListNode(val);

		if (!head) {
			head = newNode;
			tail = newNode;
		} else {
			tail->next = newNode;
			tail = newNode;
		}
		cin >> val;
	}
	return head;
}

void  print(ListNode * head) {
	ListNode * temp = head;

	while (temp) {
		cout << temp->val << " ";
		temp = temp->next;
	}
}

ListNode * merge(ListNode * head1, ListNode * head2) {
	ListNode * head = NULL, * tail = NULL;
	ListNode * t1 = head1, * t2 = head2;

	while (t1 && t2) {
		ListNode * newNode = new ListNode(-1);
		if (t1->val < t2->val) {
			newNode->val = t1->val;
			t1 = t1->next;
		} else {
			newNode->val = t2->val;
			t2 = t2->next;
		}
		if (!head) {
			head = newNode;
			tail = newNode;
		} else {
			tail->next = newNode;
			tail = newNode;
		}
	}

	while (t1) {
		ListNode * newNode = new ListNode(t1->val);
		t1 = t1->next;
		if (!head) {
			head = newNode;
			tail = newNode;
		} else {
			tail->next = newNode;
			tail = newNode;
		}
	}

	while (t2) {
		ListNode * newNode = new ListNode(t2->val);
		t2 = t2->next;
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

int main() {
	ListNode * head1 = takeInput();
	ListNode * head2 = takeInput();

	ListNode * head = merge(head1, head2);

	print(head);

	delete head1, head2, head;

	return 0;
}
