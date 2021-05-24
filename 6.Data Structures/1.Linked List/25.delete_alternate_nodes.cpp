/*

Given a Singly Linked List of integers, delete all the alternate nodes in the list.

Example:

List: 10 -> 20 -> 30 -> 40 -> 50 -> 60 -> null

Alternate nodes will be:  20, 40, and 60.

Hence after deleting, the list will be:

Output: 10 -> 30 -> 50 -> null

Note :
The head of the list will remain the same. Don't need to print or return anything.

Input format :
The first and the only line of input will contain the elements of the Singly Linked List separated by a single space and terminated by -1.

Output Format :
The only line of output will contain the updated list elements.

Input Constraints:
1 <= N <= 10^6.
Where N is the size of the Singly Linked List

Time Limit: 1sec

Sample Input 1:
1 2 3 4 5 -1

Sample Output 1:
1 3 5

Sample Input 2:
10 20 30 40 50 60 70 -1

Sample Output 2:
10 30 50 70

*/

#include<bits/stdc++.h>
#include"linked_list.h"
using namespace std;

Node<int> * delete_alternate_nodes(Node<int> * head) {
	if (!head || !head->next)
		return head;

	Node<int> * temp = head->next->next;
	head->next = NULL;
	Node<int> * nh = delete_alternate_nodes(temp);
	head->next = nh;
	return head;
}

int main() {
	Node<int> * head = takeInput();
	head = delete_alternate_nodes(head);
	cout << endl << "Updated Linked List : " << endl;
	printLL(head);
	return 0;
}