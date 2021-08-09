/*

Given the head of a linked list, rotate the list to the right by k places.

Example 1:


Input: head = [1,2,3,4,5], k = 2
Output: [4,5,1,2,3]
Example 2:


Input: head = [0,1,2], k = 4
Output: [2,0,1]


Constraints:

The number of nodes in the list is in the range [0, 500].
-100 <= Node.val <= 100
0 <= k <= 2 * 10^9

*/

#include<bits/stdc++.h>
#include"singly_linked_list.h"
using namespace std;

int len(Node * head) {
	int l = 0;
	Node * cur = head;
	while (cur) {
		l++;
		cur = cur->next;
	}
	return l;
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

Node * rotate_right(Node * head, int k) {

	int l = len(head);

	if (!l || l == 1 || !k || k % l == 0)
		return head;

	k %= l;

	head = reverse(head);
	Node * prev = NULL, * cur = head;

	while (k--) {
		prev = cur;
		cur = cur->next;
	}

	prev->next = NULL;
	prev = reverse(head);
	cur = reverse(cur);
	head->next = cur;

	return prev;
}

int main() {
	int n;
	cin >> n;

	Node * head = takeInput(n);

	int k;
	cin >> k;

	head = rotate_right(head, k);

	printLL(head);

	delete head;

	return 0;
}