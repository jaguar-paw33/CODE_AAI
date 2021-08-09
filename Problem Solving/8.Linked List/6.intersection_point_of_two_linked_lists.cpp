/*

Write a program to find the node at which the intersection of two singly linked lists begins.

For example, the following two linked lists:



begin to intersect at node c1.

Example 1:



Input: intersectVal = 8, listA = [4,1,8,4,5], listB = [5,0,1,8,4,5], skipA = 2, skipB = 3

Output: Reference of the node with value = 8

Input Explanation: The intersected node's value is 8 (note that this must not be 0 if the two lists intersect). From the head of A, it reads as [4,1,8,4,5]. From the head of B, it reads as [5,0,1,8,4,5]. There are 2 nodes before the intersected node in A; There are 3 nodes before the intersected node in B.

Example 2:



Input: intersectVal = 2, listA = [0,9,1,2,4], listB = [3,2,4], skipA = 3, skipB = 1

Output: Reference of the node with value = 2

Input Explanation: The intersected node's value is 2 (note that this must not be 0 if the two lists intersect). From the head of A, it reads as [0,9,1,2,4]. From the head of B, it reads as [3,2,4]. There are 3 nodes before the intersected node in A; There are 1 node before the intersected node in B.

Example 3:



Input: intersectVal = 0, listA = [2,6,4], listB = [1,5], skipA = 3, skipB = 2

Output: null

Input Explanation: From the head of A, it reads as [2,6,4]. From the head of B, it reads as [1,5]. Since the two lists do not intersect, intersectVal must be 0, while skipA and skipB can be arbitrary values.

Explanation: The two lists do not intersect, so return null.

Notes:

If the two linked lists have no intersection at all, return null.

The linked lists must retain their original structure after the function returns.

You may assume there are no cycles anywhere in the entire linked structure.

Your code should preferably run in O(n) time and use only O(1) memory.

Level: Easy

Problem Practice Link: https://leetcode.com/problems/intersection-of-two-linked-lists/

c-code: https://ideone.com/JReIKZ

Python code : https://onlinegdb.com/HJuRBpC9S

Similar Questions:

Minimum index sum of two lists: https://leetcode.com/problems/minimum-index-sum-of-two-lists/

*/

#include<bits/stdc++.h>
#include"singly_linked_list.h"
using namespace std;

int length(Node * head) {
	int len = 0;
	Node * temp = head;
	while (temp) {
		len++;
		temp = temp->next;
	}
	return len;
}

Node * intersectionPoint(Node * h1, Node * h2) {
	int l1 = length(h1), l2 = length(h2);

	Node * ans;
	Node * t1 = h1, * t2 = h2;

	if (l1 < l2) {
		while (l1 != l2) {
			l2--;
			t2 = t2->next;
		}
	} else if (l2 < l1) {
		while (l1 != l2) {
			l1--;
			t1 = t1->next;
		}
	}
	while (t1 && t2) {
		if (t1 == t2) {
			ans = t1;
			break;
		}
		t1 = t1->next;
		t2 = t2->next;
	}
	return ans;
}

int main() {
	int n1;
	cin >> n1;

	Node * h1 = takeInput(n1);

	int n2;
	cin >> n2;

	Node * h2 = takeInput(n2);

	cout << intersectionPoint(h1, h2)->data << endl;

	delete h1, h2;

	return 0;
}