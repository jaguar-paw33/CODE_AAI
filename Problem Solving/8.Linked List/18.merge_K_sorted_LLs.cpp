/*

Merge k sorted linked lists and return it as one sorted list.

Example:


Input:

  1->4->5,

  1->3->4,

  2->6

Output: 1->1->2->3->4->4->5->6

Leetcode Link: https://leetcode.com/problems/merge-k-sorted-lists/

*/

#include<bits/stdc++.h>
#include"singly_linked_list.h"
using namespace std;

Node * merge_K_sorted(vector<Node *> & lists) {

	priority_queue < pair<int, Node *> , vector <pair<int, Node *>>, greater<pair<int, Node *>>> minHeap;
	Node * head = NULL, * tail = NULL;

	for (int i = 0; i < lists.size(); i++) {
		if (lists[i]) {
			Node * cur = lists[i];
			minHeap.push(pair<int, Node *>(cur->data, cur));
			cur = cur->next;
			lists[i] = cur;
		}
	}

	while (minHeap.size()) {
		Node * cur = minHeap.top().second;

		if (!head) {
			head = cur;
			tail = cur;
		} else {
			tail->next = cur;
			tail = cur;
		}
		minHeap.pop();
		if (cur->next) {
			minHeap.push(pair<int, Node*>(cur->next->data, cur->next));
		}
	}

	return head;
}

int main() {
	int K;
	cin >> K;

	vector<Node *> lists;

	while (K--) {
		int n;
		cin >> n;
		Node * head = takeInput(n);
		lists.push_back(head);
	}

	Node * head = merge_K_sorted(lists);

	printLL(head);

	delete head;

	return 0;
}

