/*

You have been given a singly linked list of integers along with two integers, 'i,' and 'j.' Swap the nodes that are present at the 'i-th' and 'j-th' positions.

Note :
Remember, the nodes themselves must be swapped and not the datas.

No need to print the list, it has already been taken care. Only return the new head to the list.

Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

The first line of each test case or query contains the elements of the singly linked list separated by a single space.

The second line of input contains two integer values 'i,' and 'j,' respectively. A single space will separate them.

Remember/consider :
While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element

Output format :
For each test case/query, print the elements of the updated singly linked list.

Output for every test case will be printed in a seperate line.

Constraints :
1 <= t <= 10^2
0 <= M <= 10^5
Where M is the size of the singly linked list.
0 <= i < M
0 <= j < M

Time Limit: 1sec

Sample Input 1 :
1
3 4 5 2 6 1 9 -1
3 4
Sample Output 1 :
3 4 5 6 2 1 9

Sample Input 2 :
2
10 20 30 40 -1
1 2
70 80 90 25 65 85 90 -1
0 6
Sample Output 2 :
10 30 20 40
90 80 90 25 65 85 70

*/

#include<bits/stdc++.h>
#include"linked_list.h"
using namespace std;


Node<int> * swap_nodes(Node<int> * head, int i, int j) {

	if (i == j)
		return head;

	int count = 0;

	Node<int> * prev = NULL;
	Node<int> * cur = head;

	Node<int> * prev1 = NULL;
	Node<int> * cur1 = NULL;

	Node<int> * prev2 = NULL;
	Node<int> * cur2 = NULL;

	while (cur) {
		if (count == i) {
			prev1 = prev;
			cur1 = cur;
		}

		if (count == j) {
			prev2 = prev;
			cur2 = cur;
		}
		count++;
		prev = cur;
		cur = cur->next;
	}

	if (!prev1) {
		head = cur2;
	} else {
		prev1->next = cur2;
	}

	if (!prev2) {
		head = cur1;
	} else {
		prev2->next = cur1;
	}

	Node<int> * temp = cur1->next;
	cur1->next = cur2->next;
	cur2->next = temp;

	return head;
}

int main() {
	Node<int> * head = takeInput();
	cout << "Enter the indices of the nodes to be swapped : ";
	int i, j;
	cin >> i >> j;
	head = swap_nodes(head, i, j);
	cout << "Updated Linked List : ";
	printLL(head);
	return 0;
}
