/*

Given a singly linked list of integers, sort it using 'Merge Sort.'

Note :
No need to print the list, it has already been taken care. Only return the new head to the list.

Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

The first and the only line of each test case or query contains the elements of the singly linked list separated by a single space.

Remember/Consider :
While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element

Output format :
For each test case/query, print the elements of the sorted singly linked list.

Output for every test case will be printed in a seperate line.

Constraints :
1 <= t <= 10^2
0 <= M <= 10^5
Where M is the size of the singly linked list.

Time Limit: 1sec

Sample Input 1 :
1
10 9 8 7 6 5 4 3 -1
Sample Output 1 :
3 4 5 6 7 8 9 10 

Sample Input 2 :
2
-1
10 -5 9 90 5 67 1 89 -1
Sample Output 2 :
-5 1 5 9 10 67 89 90 

*/

#include<bits/stdc++.h>
#include"linked_list.h"
using namespace std;

Node<int> * merge(Node<int> * head1, Node<int> * head2) {
	Node<int> * fh = NULL;
	Node<int> * ft = NULL;

	Node<int> * h1 = head1;
	Node<int> * h2 = head2;

	while (h1 && h2) {
		if (h1->data < h2->data) {
			if (!fh) {
				fh = h1;
				ft = h1;
			} else {
				ft->next = h1;
				ft = ft -> next;
			}
			h1 = h1->next;
		} else {
			if (!fh) {
				fh = h2;
				ft = h2;
			} else {
				ft->next = h2;
				ft = ft -> next;
			}
			h2 = h2->next;
		}
	}

	while (h1) {
		if (!fh) {
			fh = h1;
			ft = h1;
		} else {
			ft->next = h1;
			ft = ft -> next;
		}
		h1 = h1->next;
	}

	while (h2) {
		if (!fh) {
			fh = h2;
			ft = h2;
		} else {
			ft->next = h2;
			ft = ft -> next;
		}
		h2 = h2->next;
	}
	return fh;
}

Node<int> * middleNode(Node<int> * head) {
	if (!head || !head->next)
		return head;
	Node<int> * slow = head;
	Node<int> * fast = head->next;
	while (fast && fast->next) {
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
}

Node<int> * mergeSort(Node<int> * head, Node<int> * tail) {

	if (head >= tail)
		return head;

	Node <int> * mid = middleNode(head);

	Node<int> * temp = mid->next;
	mid->next = NULL;

	Node<int> * h1 = mergeSort(head, mid);
	Node<int> * h2 = mergeSort(temp, tail);

	Node<int> * fh = merge(h1, h2);

	return fh;
}

Node<int> * getTail(Node<int> * head) {
	if (!head)
		return head;
	Node<int> * temp = head;
	while (temp->next) {
		temp = temp->next;
	}
	return temp;
}

int main() {
	Node<int> * head = takeInput();
	Node<int> * tail = getTail(head);
	head = mergeSort(head, tail);
	cout << endl << "Merge Sorted Linked List : ";
	printLL(head);
	return 0;
}
