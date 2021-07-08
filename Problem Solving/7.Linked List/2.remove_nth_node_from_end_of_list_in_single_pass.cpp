/*

Given the head of a linked list, remove the nth node from the end of the list and return its head.

Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]

*/

#include<bits/stdc++.h>
using namespace std;

class ListNode {
public:
	int val;
	ListNode * next;

	ListNode(int val) {
		this->val = val;
		this->next = NULL;
	}
};


ListNode * takeInput() {
	int val;
	cin >> val;

	ListNode * head = NULL, * tail = NULL;

	while (val != -1) {
		ListNode * newNode = new ListNode(val);
		if (!head) {
			head = newNode;
			tail = newNode;
		} else {
			tail->next = newNode;
			tail = newNode;
		}
		cin >> val;
	}

	return head;
}

void print(ListNode * head) {
	ListNode * temp = head;
	while (temp) {
		cout << temp->val << " ";
		temp = temp->next;
	}
	cout << endl;
}

ListNode * delete_nth_node_from_end_single_pass(ListNode * head, int & n) {
	if (!head)
		return head;


	head->next = delete_nth_node_from_end_single_pass(head->next, n);
	n -= 1;

	if (!n) {
		ListNode * temp = head->next;
		head->next = NULL;
		delete head;
		return temp;
	}


	return head;
}


int main() {
	ListNode * head = takeInput();
	int n;
	cin >> n;

	print(head);

	head = delete_nth_node_from_end_single_pass(head, n);

	print(head);

	delete head;

	return 0;
}