/*

You have been given a linked list of integers. Your task is to write a function that deletes a node from a given position, 'pos'.

Note :
Assume that the Indexing for the linked list always starts from 0.

If the position is greater than or equal to the length of the linked list, you should return the same linked list without any change.

Illustration :
The following images depict how the deletion has been performed.

Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

The first line of each test case or query contains the elements of the linked list separated by a single space. 

The second line of each test case contains the integer value of 'pos'. It denotes the position in the linked list from where the node has to be deleted.

Remember/Consider :
While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element

Output format :
For each test case/query, print the resulting linked list of integers in a row, separated by a single space.

Output for every test case will be printed in a separate line.

You don't need to print explicitly, it has been taken care of.

Constraints :
1 <= t <= 10^2
0 <= N <= 10^5
pos >= 0

Time Limit: 1sec

Where 'N' is the size of the singly linked list.

Sample Input 1 :
1 
3 4 5 2 6 1 9 -1
3
Sample Output 1 :
3 4 5 6 1 9

Sample Input 2 :
2
3 4 5 2 6 1 9 -1
0
10 20 30 40 50 60 -1
7
Sample Output 2 :
4 5 2 6 1 9
10 20 30 40 50 60

*/

#include<bits/stdc++.h>
#include"linked_list.h"
using namespace std;

Node<int> * delNode(Node<int> * head, int i) {
	if (!head)
		return NULL;

	Node<int> * prev = NULL;
	Node<int> * cur = head;

	while (i-- && cur)
	{
		prev = cur;
		cur = cur->next;
	}
	if (!prev)
	{
		cur = cur->next;
		head->next = NULL;
		delete head;
		head = cur;
	} else {
		if (!cur)
			return head;
		else {
			prev->next = cur->next;
			cur->next = NULL;
			delete cur;
		}
	}
	return head;
}

int main() {
	Node<int> * head = takeInput();
	printLL(head);
	cout << endl << "Enter the value of i : ";
	int i;
	cin >> i;
	head = delNode(head, i);
	cout << endl << "Updated Linked List : ";
	printLL(head);
	return 0;
}
