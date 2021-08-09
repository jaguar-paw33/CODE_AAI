/*

Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

You may not alter the values in the list's nodes, only nodes themselves may be changed.

Example 1:


Input: head = [1,2,3,4,5], k = 2
Output: [2,1,4,3,5]
Example 2:


Input: head = [1,2,3,4,5], k = 3
Output: [3,2,1,4,5]
Example 3:

Input: head = [1,2,3,4,5], k = 1
Output: [1,2,3,4,5]
Example 4:

Input: head = [1], k = 1
Output: [1]


Constraints:

The number of nodes in the list is in the range sz.
1 <= sz <= 5000
0 <= Node.val <= 1000
1 <= k <= sz


Follow-up: Can you solve the problem in O(1) extra memory space?

*/


#include<bits/stdc++.h>
#include"singly_linked_list.h"
using namespace std;

int len(Node * head) {
	int len = 0;
	Node * cur = head;
	while (cur) {
		len++;
		cur = cur->next;
	}
	return len;
}

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

Node * reverse_k(Node * head, int k) {
	if (!head || !head->next)
		return head;

	int l = len(head);

	Node * h = head, *t = NULL, *prev = NULL, *cur = head;

	for (int i = 0; i < l / k; i++) {
		int count = k;
		while (count--) {
			prev = cur;
			cur = cur->next;
		}
		prev->next = NULL;
		Node * temp = reverse(h);

		if (!i)
			head = prev;
		if (t)
			t->next = prev;

		t = h;
		h->next = cur;
		h = cur;
	}

	return head;
}

int main() {
	int n;
	cin >> n;

	Node * head = takeInput(n);

	int k;
	cin >> k;

	head = reverse_k(head, k);

	printLL(head);

	delete head;

	return 0;
}