// This method can be used to represent large digit numbers and operate on them.

/*

Given two numbers represented by two linked lists, write a function that returns sum list. The sum list is linked list representation of addition of two input numbers. It is not allowed to modify the lists. Also, not allowed to use explicit extra space

Example

Input: First List: 5->6->3 // represents number 563 Second List: 8->4->2 // represents number 842 Output Resultant list: 1->4->0->5 // represents number 1405

Input Format

First line contains two integers N and M denoting the size of linked lists. Second line contains a string of size N representing the elements of first linked list (first number). Third line contains a string of size M representing the elements of second linked list (second number)

Constraints

1 <= N, M <= 10^5

Output Format

Print the string denoting the sum of two linkedlists.

Sample Input 0

3 4
999
1000

Sample Output 0

1999

Hackerrank Link: https://www.hackerrank.com/contests/applied-course/challenges/add-two-numbers-1-1-1

*/

#include<bits/stdc++.h>
#include"singly_linked_list.h"
using namespace std;

// Using Stack
Node * sum1(Node * h1, Node * h2) {

	stack<int> s1, s2;
	Node * t1 = h1, * t2 = h2;

	while (t1) {
		s1.push(t1->data);
		t1 = t1->next;
	}
	while (t2) {
		s2.push(t2->data);
		t2 = t2->next;
	}

	Node * h = NULL;

	int s, r = 0;

	while (s1.size() && s2.size()) {
		s = s1.top() + s2.top() + r;
		s1.pop();
		s2.pop();

		r = s / 10;
		s %= 10;

		Node * newNode = new Node(s);

		newNode->next = h;
		h = newNode;
	}

	while (s1.size()) {
		s = s1.top() + r;
		s1.pop();

		r = s / 10;
		s %= 10;

		Node * newNode = new Node(s);

		newNode->next = h;
		h = newNode;
	}

	while (s2.size()) {
		s = s2.top() + r;
		s2.pop();

		r = s / 10;
		s %= 10;

		Node * newNode = new Node(s);

		newNode->next = h;
		h = newNode;
	}

	if (r) {
		Node * newNode = new Node(r);
		newNode->next = h;
		h = newNode;
	}

	return h;
}

Node * reverse(Node * head) {
	Node * prev = NULL, * cur = head;
	while (cur) {
		Node * temp = cur->next;
		cur->next = prev;
		prev = cur;
		cur = temp;
	}
	return prev;
}


// Using Reverse
Node * sum2(Node * h1, Node * h2) {

	h1 = reverse(h1);
	h2 = reverse(h2);

	Node * h = NULL;

	Node * t1 = h1, * t2 = h2;
	int s, r = 0;

	while (t1 && t2) {
		s = t1->data + t2->data + r;
		r = s / 10;
		s %= 10;
		Node * newNode = new Node(s);
		if (!h) {
			h = newNode;
		} else {
			newNode ->next = h;
			h = newNode;
		}
		t1 = t1->next;
		t2 = t2->next;
	}

	while (t1) {
		s = t1->data + r;
		r = s / 10;
		s %= 10;
		Node * newNode = new Node(s);
		if (!h) {
			h = newNode;
		} else {
			newNode ->next = h;
			h = newNode;
		}
		t1 = t1->next;
	}

	while (t2) {
		s = t2->data + r;
		r = s / 10;
		s %= 10;
		Node * newNode = new Node(s);
		if (!h) {
			h = newNode;
		} else {
			newNode ->next = h;
			h = newNode;
		}
		t2 = t2->next;
	}
	if (r) {
		Node * newNode = new Node(r);
		newNode->next = h;
		h = newNode;
	}

	h1 = reverse(h1);
	h2 = reverse(h2);

	return h;
}

int main() {
	int n1, n2;
	cin >> n1 >> n2;

	Node * h1 = takeInput(n1);
	Node * h2 = takeInput(n2);

	Node * h = sum1(h1, h2);
	printLL(h);

	h = sum2(h1, h2);
	printLL(h);

	delete h1, h2, h;

	return 0;
}