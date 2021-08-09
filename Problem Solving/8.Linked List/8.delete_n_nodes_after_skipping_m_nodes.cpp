/*

Write a program to delete n Nodes in the linked list after skipping m Nodes in the linked list.

Input Format

First line contains the N size of input elements followed by n and m.
Second line contains N integer values
Constraints

1 < N < 10^6

Output Format

In output print the list after deleting the nodes.

Sample Input 0

7 1 2
1 2 3 4 5 6 7
Sample Output 0

1 2 4 5 7

*/

#include<bits/stdc++.h>
#include"singly_linked_list.h"
using namespace std;

Node * delete_n_nodes_after_skipping_m(Node * head, int n, int m) {
	if (!n)
		return head;

	if (!m)
	{
		delete head;
		return NULL;
	}


	Node * prev = NULL, * cur = head;

	while (cur) {

		for (int i = 0; i < m && cur; i++) {
			prev = cur;
			cur = cur->next;
		}

		if (cur) {
			for (int i = 0; i < n - 1 && cur; i++) {
				cur = cur->next;
			}

			Node * temp = prev->next;
			prev->next = NULL;

			if (cur) {
				prev->next = cur->next;
				cur->next = NULL;
				cur = prev->next;
			}

			delete temp;
		}

	}
	return head;
}


int main() {
	int N;
	cin >> N;

	Node * head = takeInput(N);

	int n, m;
	cin >> n >> m;

	head = delete_n_nodes_after_skipping_m(head, n, m);

	printLL(head);

	delete head;

	return 0;
}