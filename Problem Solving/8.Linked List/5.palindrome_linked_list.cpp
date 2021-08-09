/*

Given a singly linked list, determine if it is a palindrome.

Example 1:

Input: 1->2

Output: false


Example 2:

Input: 1->2->2->1

Output: true


Follow up:

Could you do it in O(n) time and O(1) space?



Level: Easy

Problem Practice Link: https://leetcode.com/problems/palindrome-linked-list/


c-code: https://ideone.com/W31DiJ

Python Code : https://onlinegdb.com/BySl35LbL



Similar Problems:

1. Valid Palindrome: https://leetcode.com/problems/valid-palindrome/

2. Palindrome Number: https://leetcode.com/problems/palindrome-number/

*/


#include<bits/stdc++.h>
#include"singly_linked_list.h"
using namespace std;

// Time Complexity - O(n) and Space Complexity - O(n)
bool is_palindrome1(Node * head) {
	stack<int> s;
	Node * temp = head;
	while (temp) {
		s.push(temp->data);
		temp = temp->next;
	}
	temp = head;
	while (temp) {
		if (temp->data != s.top()) {
			return false;
		}
		temp = temp->next;
		s.pop();
	}
	return true;
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

Node* midNode(Node* head) {
	Node * slow = head, * fast = head->next;
	while (fast && fast->next) {
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
}


// Time Complexity - O(n) and Space Complexity - O(1)
bool is_palindrome2(Node * head) {
	Node * mid = midNode(head);
	Node * after = mid->next;
	mid->next = NULL;
	after = reverse(after);
	Node * t1 = head, * t2 = after;
	while (t1 && t2) {
		if (t1->data != t2->data) {
			after = reverse(after);
			mid->next = after;
			return false;
		}
		t1 = t1->next;
		t2 = t2->next;
	}
	after = reverse(after);
	mid->next = after;
	return true;
}

bool helper(Node** head, Node* tail) {
	if (!tail)
		return true;
	bool ans = helper(head, tail->next);
	if ((*head)->data != tail->data)
		return false;
	*head = (*head)->next;
	return ans;
}

//Recursive O(n) Solution
bool is_palindrome3(Node * head) {
	return helper(&head, head);
}

int main() {
	int n;
	cin >> n;

	Node * head = takeInput(n);

	printLL(head);

	cout << is_palindrome1(head) << endl;
	cout << is_palindrome2(head) << endl;
	cout << is_palindrome3(head) << endl;

	printLL(head);


	return 0;
}


