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

Node * middle(Node * head) {
	Node * slow = head, * fast = head; // if mid = ceil(n/2) for even n
	// Node * slow = head, * fast = head->next; // if mid = floor(n/2) for even n

	while (fast && fast->next) {
		slow = slow->next;
		fast = fast->next->next;
	}

	return slow;
}

int main() {
	int n;
	cin >> n;

	Node * head = takeInput(n);

	Node * mid = middle(head);

	printLL(mid);

	delete head, mid;

	return 0;
}