/*

For a given singly linked list of integers, arrange the elements such that all the even numbers are placed after the odd numbers. The relative order of the odd and even terms should remain unchanged.

Note :
No need to print the list, it has already been taken care. Only return the new head to the list.

Input format:
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

The first line of each test case or query contains the elements of the singly linked list separated by a single space.

Remember/Consider :
While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element

Output format:
For each test case/query, print the elements of the updated singly linked list.

Output for every test case will be printed in a seperate line.

Constraints :
1 <= t <= 10^2
0 <= M <= 10^5
Where M is the size of the singly linked list.

Time Limit: 1sec

Sample Input 1 :
1
1 4 5 2 -1
Sample Output 1 :
1 5 4 2

Sample Input 2 :
2
1 11 3 6 8 0 9 -1
10 20 30 40 -1
Sample Output 2 :
1 11 3 9 6 8 0
10 20 30 40

*/


#include<bits/stdc++.h>
#include"linked_list.h"
using namespace std;

Node<int> * even_after_odd(Node<int> * head) {

	Node<int> * eh = NULL;
	Node<int> * et = NULL;
	Node<int> * oh = NULL;
	Node<int> * ot = NULL;
	Node<int> * temp = head;

	while (temp) {

		Node<int> * newNode = new Node<int> (temp->data);

		if (temp->data % 2) {
			if (!oh) {
				oh = newNode;
				ot = newNode;
			} else {
				ot->next = newNode;
				ot = ot->next;
			}
		} else {
			if (!eh) {
				eh = newNode;
				et = newNode;
			} else {
				et->next = newNode;
				et = et->next;
			}
		}

		temp = temp->next;
	}

	if (!oh)
		return eh;
	else {
		ot->next = eh;
	}
	return oh;
}

int main() {
	Node<int> * head = takeInput();
	Node<int> * nh = even_after_odd(head);
	cout << "Updated Linekd List : ";
	printLL(nh);
	return 0;
}
