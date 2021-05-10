/*

Given a singly linked list of integers, sort it using 'Bubble Sort.'

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
0 <= M <= 10^3
Where M is the size of the singly linked list.

Time Limit: 1sec

Sample Input 1 :
1
10 9 8 7 6 5 4 3 -1
Sample Output 1 :
3 4 5 6 7 8 9 10

Sample Output 2 :
2
-1
10 -5 9 90 5 67 1 89 -1
Sample Output 2 :
-5 1 5 9 10 67 89 90

*/


#include<bits/stdc++.h>
#include"linked_list.h"
using namespace std;

int length_LL(Node<int> * head) {
	int l = 0;

	Node<int> * temp = head;

	while (temp) {
		l++;
		temp = temp->next;
	}

	return l;
}

Node<int> * bubble_sort(Node<int> * head) {

	if (!head || !head->next)
		return head;

	int l = length_LL(head);

	for (int i = l - 1; i > 0; i--) {

		Node<int> * prev = NULL;
		Node<int> * cur = head;

		bool swapped = false;

		for (int j = 1; j <= i; j++) {

			if (cur->data > cur->next->data) {

				if (!prev) {

					head = cur->next;
					Node<int> * temp = cur->next->next;
					cur->next->next = cur;
					cur->next = temp;
					prev = head;
					cur = prev->next;

				} else {

					Node<int> * temp = cur->next->next;
					prev->next = cur->next;
					cur->next->next = cur;
					cur->next = temp;
					prev = prev->next;

				}

				swapped = true;

			} else {
				prev = cur;
				cur = cur->next;
			}
		}
		if (!swapped)
			return head;
	}

	return head;

}

int main() {
	Node<int> * head = takeInput();
	head = bubble_sort(head);
	cout << "Sorted Linked List : ";
	printLL(head);
	return 0;
}