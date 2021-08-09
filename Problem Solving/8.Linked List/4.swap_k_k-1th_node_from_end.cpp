/*

Given a linked list, swap the k-th node and (k-1)th node of linked list from the end of linked list.

Input Format

First line contains two integers N and K. Next line contains N space separated integers denoting elements of Linked List.

Constraints

1 <= N <= 10^5
1 <= K < N
Output Format

Print the required list after swapping nodes.

Sample Input 0

4 3
10 3 1 9
Sample Output 0

10 1 3 9

*/

#include<bits/stdc++.h>
#include"singly_linked_list.h"
using namespace std;

Node * swap_nodes_from_end(Node * head, int k) {
	Node * prev = NULL, * cur = head, * after = head;
	while (--k) {
		after = after->next;
	}
	while (after->next) {
		prev = cur;
		cur = cur->next;
		after = after->next;
	}

	if (!prev) {
		head = cur->next;
		cur->next = head->next;
		head->next = cur;
	} else {
		prev->next = cur->next;
		cur->next = cur->next->next;
		prev->next->next = cur;
	}

	return head;
}


int main() {
	int n;
	cin >> n;

	Node * head = takeInput(n);

	int k;
	cin >> k;

	printLL(head);

	head = swap_nodes_from_end(head, k);

	printLL(head);

	return 0;
}
