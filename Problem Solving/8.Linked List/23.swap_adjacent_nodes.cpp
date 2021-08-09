/*

Given a linked list, swap every two adjacent nodes and return its head. You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)

Example 1:

Input: head = [1,2,3,4]
Output: [2,1,4,3]
Example 2:

Input: head = []
Output: []
Example 3:

Input: head = [1]
Output: [1]


Constraints:

The number of nodes in the list is in the range [0, 100].
0 <= Node.val <= 100

*/

#include<bits/stdc++.h>
#include"singly_linked_list.h"
using namespace std;

Node * swap_adjacent_nodes(Node * head) {
	if (!head || !head->next)
		return head;

	Node * prev_prev = NULL, *prev = head, * cur = head->next;

	while (cur) {

		Node * temp = cur->next;
		cur->next = prev;
		prev->next = temp;

		if (!prev_prev) {
			head = cur;
		} else {
			prev_prev->next = cur;
		}

		if (!temp || !temp->next)
			break;

		prev_prev = prev;
		prev = temp;
		cur = temp->next;
	}

	return head;
}

int main() {
	int n;
	cin >> n;

	Node * head = takeInput(n);

	head = swap_adjacent_nodes(head);

	printLL(head);

	delete head;

	return 0;
}