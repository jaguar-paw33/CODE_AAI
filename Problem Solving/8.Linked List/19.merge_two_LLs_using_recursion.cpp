/*

Write a function that takes two lists, each of which is sorted in increasing order, and merges the two together into one list which is in increasing order. function should return the new list. The new list should be made by splicing together the nodes of the first two lists.

Implement using Recursion

Input Format

First list consists of N interger values Second list consists of M integer values

Constraints

1 <= N, M <= 10^5
Output Format

Print the list after merging the lists

Sample Input 0

3 5
2 6 10
1 4 5 5 9
Sample Output 0

1 2 4 5 5 6 9 10

*/

#include<bits/stdc++.h>
#include"singly_linked_list.h"
using namespace std;


Node * merge(Node * h1, Node * h2) {
	if (!h1)
		return h2;
	else if (!h2)
		return h1;

	Node * head = NULL;

	if (h1->data < h2->data) {
		head = merge(h1->next, h2);
		h1->next = head;
		return h1;
	} else {
		head = merge(h1, h2->next);
		h2->next = head;
		return h2;
	}
}

int main() {
	int n1, n2;
	cin >> n1 >> n2;

	Node * h1 = takeInput(n1);
	Node * h2 = takeInput(n2);

	Node * h = merge(h1, h2);

	printLL(h);

	delete h;

	return 0;
}