/*

Given a node from a Circular Linked List which is sorted in ascending order, write a function to insert a value insertVal into the list such that it remains a sorted circular list. The given node can be a reference to any single node in the list, and may not be necessarily the smallest value in the circular list.

If there are multiple suitable places for insertion, you may choose any place to insert the new value. After the insertion, the circular list should remain sorted.

If the list is empty (i.e., given node is null), you should create a new single circular list and return the reference to that single node. Otherwise, you should return the original given node.



Example 1:






Input: head = [3,4,1], insertVal = 2

Output: [3,4,1,2]

Explanation: In the figure above, there is a sorted circular list of three elements. You are given a reference to the node with value 3, and we need to insert 2 into the list. The new node should be inserted between node 1 and node 3. After the insertion, the list should look like this, and we should still return node 3.








Example 2:



Input: head = [], insertVal = 1

Output: [1]

Explanation: The list is empty (given head is null). We create a new single circular list and return the reference to that single node.


Example 3:



Input: head = [1], insertVal = 0

Output: [1,0]




Constraints:



0 <= Number of Nodes <= 5 * 10^4

-10^6 <= Node.val <= 10^6

-10^6 <= insertVal <= 10^6



Level: Medium

Problem Practice Link: https://leetcode.com/problems/insert-into-a-sorted-circular-linked-list/



Similar Problems:

Insertions Sort List: https://leetcode.com/problems/insertion-sort-list/

*/


#include<bits/stdc++.h>
using namespace std;

class Node {
public:
	int data;
	Node * next;

	Node(int data) {
		this->data = data;
		this->next = NULL;
	}
};

Node * takeInput(int n) {
	int data;

	Node * head = NULL, *tail = NULL;

	while (n--) {
		cin >> data;
		Node * newNode = new Node(data);
		if (!head) {
			head = newNode;
			tail = newNode;
		} else {
			tail->next = newNode;
			tail = newNode;
		}
	}
	if (head) {
		tail->next = head;
	}
	return head;
}

void printLL(Node * head) {
	Node * prev = NULL, *cur = head;
	while (!prev || prev->next != head) {
		cout << cur->data << " ";
		prev = cur;
		cur = cur->next;
	}
	cout << endl;
}

Node * insert(Node * head, int data) {
	Node * newNode = new Node(data);
	newNode->next = newNode;

	if (!head)
		return newNode;

	Node * prev = head, * cur = head;

	while (prev->next != head) {
		prev = prev->next;
	}

	bool begin = true;

	Node * maxNode = cur, * minNode = cur;

	while (begin || cur != head) {

		if (begin)
			begin = false;

		if (cur->data > newNode->data && prev->data <= newNode->data) {
			newNode->next = cur;
			prev->next = newNode;
			return head;
		}

		if (cur->data > maxNode->data) {
			maxNode = cur;
		} else {
			minNode = cur;
		}

		prev = cur;
		cur = cur->next;

	}


	if (!begin && cur == head) {
		if (newNode->data <= minNode->data) {
			newNode->next = minNode;
			prev->next = newNode;
			head = newNode;
		} else {
			Node * temp = maxNode->next;
			maxNode->next = newNode;
			newNode->next = temp;
		}
	}

	return head;
}

int main() {
	int n;
	cin >> n;

	Node * head = takeInput(n);

	int data;
	cin >> data;

	head = insert(head, data);

	printLL(head);

	return 0;
}


