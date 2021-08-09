/*

Given the head of a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list. Return the linked list sorted as well.

Example 1:

Input: head = [1,2,3,3,4,4,5]
Output: [1,2,5]
Example 2:


Input: head = [1,1,1,2,3]
Output: [2,3]


Constraints:

The number of nodes in the list is in the range [0, 300].
-100 <= Node.val <= 100
The list is guaranteed to be sorted in ascending order.

*/

#include<bits/stdc++.h>
#include"singly_linked_list.h"
using namespace std;

Node * remove_duplicates(Node * head) {
	if (!head || !head->next)
		return head;

	Node * dummy = new Node(101);
	dummy->next = head;
	Node * prev = dummy, * cur = head;
	while (cur) {

		if (cur->next && cur->data == cur->next->data) {
			cur = cur->next;
			continue;
		} else if (prev->next != cur) {
			prev->next = cur->next;
			cur = cur->next;
			continue;
		}

		prev = cur;
		cur = cur->next;

	}
	head = dummy->next;
	return head;
}

int main() {
	int n;
	cin >> n;

	Node * head = takeInput(n);

	head = remove_duplicates(head);

	printLL(head);

	delete head;

	return 0;
}