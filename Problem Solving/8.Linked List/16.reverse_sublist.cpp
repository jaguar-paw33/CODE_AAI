/*

We are given a linked list and positions m and n. We need to reverse the linked list from position m to n. Write a program to reverse the list from m to n.

Input Format

First line contains three integers K, N and M. Next line contains K space separated integers denoting the elements of linked list.

Constraints

1 <= K <= 10^5 1 <= N <= M <= K

Output Format

Print the list after reversing from m to n.

Sample Input 0

7 1 4
1 2 3 4 5 6 7
Sample Output 0

4 3 2 1 5 6 7

*/

#include<bits/stdc++.h>
#include"singly_linked_list.h"
using namespace std;

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

Node * reverse_sublist(Node * head, int start, int end) {

	if (!head || !head->next)
		return head;

	Node * p1 = NULL, * c1 = NULL, *p2 = NULL, * c2 = NULL;
	Node * prev = NULL, * cur = head;
	int num = 1;

	while (cur) {
		if (num == start) {
			p1 = prev;
			c1 = cur;
		}

		if (num == end + 1) {
			p2 = prev;
			c2 = cur;
		}

		prev = cur;
		cur = cur->next;
		num += 1;
	}

	if (!p2)
		return head;

	p2->next = NULL;

	if (!p1) {
		head = reverse(c1);
	}
	else {
		p1->next = reverse(c1);
	}

	c1->next = c2;

	return  head;

}


int main() {
	int n;
	cin >> n;

	Node * head = takeInput(n);

	int start, end;

	cin >> start >> end;

	head = reverse_sublist(head, start, end);

	printLL(head);

	delete head;

	return 0;
}