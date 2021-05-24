/*

Given a large number represented in the form of a linked list. Write code to increment the number by 1 in-place(i.e. without using extra space).

Note: You don't need to print the elements, just update the elements and return the head of updated LL.

Input Constraints:
1 <= Length of Linked List <=10^6.

Input format :
Line 1 : Linked list elements (separated by space and terminated by -1)

Output Format :
Line 1: Updated linked list elements

Sample Input 1 :
3 9 2 5 -1
Sample Output 1 :
3 9 2 6

Sample Input 2 :
9 9 9 -1
Sample Output 1 :
1 0 0 0

*/

#include<bits/stdc++.h>
#include "linked_list.h"
using namespace std;

Node<int> * next_number(Node<int> * head) {

	if (!head->next) {

		head->data += 1;
		return head;

	}

	Node<int> * temp = next_number(head->next);
	head->data += temp->data / 10;
	temp->data %= 10;
	head->next = temp;
	return head;
}

Node<int> * nextNumber(Node<int> * head) {

	if (!head)
		return head;

	Node<int> * ans = next_number(head);
	if (ans->data / 10 == 0) {
		return ans;
	} else {
		Node<int>* newNode = new Node<int>(ans->data / 10);
		ans->data %= 10;
		newNode->next = ans;
		return newNode;
	}
}



int main() {
	Node<int> * head = takeInput();

	Node<int> * nh = next_number(head);

	printLL(nh);

	return 0;
}