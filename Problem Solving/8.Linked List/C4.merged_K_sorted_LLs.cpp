/*

You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.

Example 1:

Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list:
1->1->2->3->4->4->5->6

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

void  print(ListNode * head) {
	ListNode * temp = head;

	while (temp) {
		cout << temp->val << " ";
		temp = temp->next;
	}
}

ListNode * merge(vector<ListNode * > lists) {

	ListNode * head = NULL, * tail = NULL;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	for (int i = 0; i < lists.size(); i++) {
		ListNode * head = lists[i];
		if (head) {
			pq.push(make_pair(head->val, i));
			lists[i] = lists[i]->next;
		}
	}

	while (pq.size()) {

		pair<int, int> p = pq.top();
		pq.pop();

		ListNode * newNode = new ListNode(p.first);

		if (lists[p.second]) {
			pq.push(make_pair(lists[p.second]->val, p.second));
			lists[p.second] = lists[p.second]->next;
		}

		if (!head) {
			head = newNode;
			tail = newNode;
		} else {
			tail->next = newNode;
			tail = newNode;
		}

	}

	return head;

}

int main() {
	int n;
	cin >> n;

	vector<ListNode * > lists;

	while (n--) {
		ListNode * head = takeInput();
		lists.push_back(head);
	}

	ListNode * head = merge(lists);

	print(head);

	delete head;

	return 0;
}