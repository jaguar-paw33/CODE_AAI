/*

Given the head of a singly linked list, reverse the list, and return the reversed list.



Example 1:


Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]
Example 2:


Input: head = [1,2]
Output: [2,1]
Example 3:

Input: head = []
Output: []


Constraints:

The number of nodes in the list is the range [0, 5000].
-5000 <= Node.val <= 5000


Follow up: A linked list can be reversed either iteratively or recursively. Could you implement both?

*/


#include<bits/stdc++.h>
#include"singly_linked_list.h"
using namespace std;

Node * reverse_recursive(Node * head) {
	if (!head || !head->next)
		return head;

	Node * t = reverse_recursive(head->next);
	head->next->next = head;
	head->next = NULL;
	return t;
}

Node * reverse_iterative(Node * head) {
	Node * prev = NULL, * cur = head;

	while (cur) {
		Node * temp = cur->next;
		cur->next = prev;
		prev = cur;
		cur = temp;
	}

	return prev;
}

int main() {
	int n;
	cin >> n;

	Node * head = takeInput(n);

	// head = reverse_recursive(head);
	// printLL(head);

	head = reverse_iterative(head);
	printLL(head);

	delete head;

	return 0;
}



