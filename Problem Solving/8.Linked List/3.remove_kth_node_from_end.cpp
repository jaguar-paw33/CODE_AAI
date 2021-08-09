/*

Given a linked list, remove the n-th node from the end of list and return its head.

Example:

Given linked list: 1->2->3->4->5, and n = 2.

After removing the second node from the end, the linked list becomes 1->2->3->5.

Note:

Given n will always be valid.

Follow up:

Could you do this in one pass?


Level: Medium

Problem Practice link: https://leetcode.com/problems/remove-nth-node-from-end-of-list/

Python Code: https://ideone.com/heeLGx

*/

#include<bits/stdc++.h>
#include"singly_linked_list.h"
using namespace std;

// Single Pass
Node * remove_nth_from_end(Node * head, int n) {
	Node * prev = NULL, * cur = head, * after = head;
	while (--n) {
		after = after->next;
	}
	while (after->next) {
		prev = cur;
		cur = cur->next;
		after = after->next;
	}
	if (!prev) {
		head = head->next;
	} else {
		prev->next = cur->next;
	}

	cur->next = NULL;
	delete cur;
	return head;
}

int main() {
	int n;
	cin >> n;

	Node * head = takeInput(n);

	int k;
	cin >> k;

	printLL(head);

	head = remove_nth_from_end(head, k);

	printLL(head);

	return 0;
}