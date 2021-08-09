/*

Merge two sorted linked lists and return it as a sorted list. The list should be made by splicing together the nodes of the first two lists.

Example 1:
Input: l1 = [1,2,4], l2 = [1,3,4]
Output: [1,1,2,3,4,4]

Example 2:
Input: l1 = [], l2 = []
Output: []

Example 3:
Input: l1 = [], l2 = [0]
Output: [0]


Constraints:

The number of nodes in both lists is in the range [0, 50].
-100 <= Node.val <= 100
Both l1 and l2 are sorted in non-decreasing order.

*/

#include<bits/stdc++.h>
#include"singly_linked_list.h"
using namespace std;

Node * merge(Node * h1, Node * h2) {
	Node * h = NULL, * t = NULL;

	while (h1 && h2) {
		if (h1->data < h2->data) {
			if (!h) {
				h = h1;
				t = h1;
			} else {
				t->next = h1;
				t = h1;
			}
			h1 = h1->next;
		} else {
			if (!h) {
				h = h2;
				t = h2;
			} else {
				t->next = h2;
				t = h2;
			}
			h2 = h2->next;
		}
	}

	while (h1) {
		if (!h) {
			h = h1;
			t = h1;
		} else {
			t->next = h1;
			t = h1;
		}
		h1 = h1->next;
	}

	while (h2) {
		if (!h) {
			h = h2;
			t = h2;
		} else {
			t->next = h2;
			t = h2;
		}
		h2 = h2->next;
	}

	return h;
}

int main() {

	int n1, n2;
	cin >> n1 >> n2;

	Node * h1 = takeInput(n1);
	Node * h2 = takeInput(n2);

	Node * h = merge(h1, h2);

	printLL(h);

	delete h, h1, h2;

	return 0;
}

