/*

Problem Statement:
Given a Linked List and a number k, write a function that returns the value at the k’th node from end of the Linked List.
Example:

Given linked list: 1->2->3->4->5, and k = 2.

Output: 4

Level: Easy

Python Executalbe Code: https://onlinegdb.com/BkFiDLpqH

*/

#include<bits/stdc++.h>
#include"singly_linked_list.h"
using namespace std;


// Single Pass
int kth_from_end(Node * head, int k) {
	Node * p = head, *q = head;
	while (--k) { // Putting p and q at a gap of k-1
		q = q->next;
	}
	while (q->next) { // Moving both until q points the last element, at this time p points to the kth element from end.
		q = q->next;
		p = p->next;
	}
	return p->data;
}

int main() {
	int n;
	cin >> n;

	Node * head = takeInput(n);

	int k;
	cin >> k;

	cout << kth_from_end(head, k) << endl;

	return 0;
}
