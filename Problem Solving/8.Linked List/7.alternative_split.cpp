/*

Write a function AlternatingSplit() that takes one list and divides up its nodes to make two smaller lists ‘a’ and ‘b’. The sublists should be made from alternating elements in the original list. So if the original list is 0->1->0->1->0->1 then one sublist should be 0->0->0 and the other should be 1->1->1.

Level: Easy

c-code: https://ideone.com/zEgqaG

Python code : https://onlinegdb.com/r1lthGxoS

Similar Questions:

Split LInked lists in parts: https://leetcode.com/problems/split-linked-list-in-parts/

*/

#include<bits/stdc++.h>
#include"singly_linked_list.h"
using namespace std;

void split_and_print(Node* head) {
	Node * h1 = NULL, *t1 = NULL, * h2 = NULL, * t2 = NULL;
	Node * temp = head;
	while (temp) {
		if (!h1) {
			h1 = temp;
			t1 = temp;
		} else {
			t1->next = temp;
			t1 = temp;
		}
		temp = temp->next;
		if (temp) {
			if (!h2) {
				h2 = temp;
				t2 = temp;
			} else {
				t2->next = temp;
				t2 = temp;
			}
			temp = temp->next;
		}
	}
	t1->next = NULL;
	t2->next = NULL;
	printLL(h1);
	printLL(h2);
}

int main() {
	int n;
	cin >> n;
	Node * head = takeInput(n);
	split_and_print(head);
	delete head;
	return 0;
}