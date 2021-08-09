/*

Given head, the head of a linked list, determine if the linked list has a cycle in it.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to.

Note : that pos is not passed as a parameter.

Return true if there is a cycle in the linked list. Otherwise, return false.

Example 1:

Input: head = [3,2,0,-4], pos = 1

Output: true

Explanation: There is a cycle in the linked list, where tail connects to the second node.



Example 2:

Input: head = [1,2], pos = 0

Output: true

Explanation: There is a cycle in the linked list, where tail connects to the first node.



Example 3:

Input: head = [1], pos = -1

Output: false

Explanation: There is no cycle in the linked list.


Follow up:

Can you solve it using O(1) (i.e. constant) memory?

Level: Easy
Problem Practice Link: https://leetcode.com/problems/linked-list-cycle/

C-code: https://ideone.com/dLGKy3

Python Code: https://onlinegdb.com/S1RPWvTcH


Similar Problems:

Linked list Cycle II: https://leetcode.com/problems/linked-list-cycle-ii/

*/

#include<bits/stdc++.h>
#include"singly_linked_list.h"
using namespace std;


Node * addCycle(Node * head, int pos) {
	Node * temp = head;
	Node * to = head;
	while (temp->next) {
		if (!pos)
			to = temp;
		temp = temp->next;
		pos--;
	}
	temp->next = to;
	return head;
}

// When the minimum value lies within the valid range
bool is_loop_present1(Node * head) {
	Node * temp = head;
	while (temp && temp->data != INT_MIN) {
		temp->data = INT_MIN;
		temp = temp->next;
	}
	if (!temp)
		return false;
	else
		return true;
}


bool is_loop_present2(Node * head) {
	Node* prev = NULL, * cur = head;
	while (cur) {
		Node * temp = cur->next;
		cur->next = prev;
		prev = cur;
		cur = temp;
		if (cur == head)
			return true;
	}
	return false;
}


// Approach 1 and Approach 2 change the structure of the linked list, but the below approach does not
// Floyd's cycle detection algorithm (slow and fast pointers)
bool is_loop_present3(Node * head) {
	Node * slow = head, * fast = head;
	while (slow && fast && fast->next) {
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast)
			return true;
	}
	return false;
}



int main() {
	int n;
	cin >> n;

	Node * head = takeInput(n);

	int pos;
	cin >> pos;

	if (pos != -1)
		head = addCycle(head, pos);

	// cout << is_loop_present1(head) << endl;
	// cout << is_loop_present2(head) << endl;
	cout << is_loop_present3(head) << endl;

	return 0;
}