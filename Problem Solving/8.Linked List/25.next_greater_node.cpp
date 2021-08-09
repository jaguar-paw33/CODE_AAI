/*

You are given the head of a linked list with n nodes.

For each node in the list, find the value of the next greater node. That is, for each node, find the value of the first node that is next to it and has a strictly larger value than it.

Return an integer array answer where answer[i] is the value of the next greater node of the ith node (1-indexed). If the ith node does not have a next greater node, set answer[i] = 0.


Example 1:


Input: head = [2,1,5]
Output: [5,5,0]
Example 2:


Input: head = [2,7,4,3,5]
Output: [7,0,5,5,0]


Constraints:

The number of nodes in the list is n.
1 <= n <= 10^4
1 <= Node.val <= 10^9


*/


#include<bits/stdc++.h>
#include"singly_linked_list.h"
using namespace std;

Node * reverse_LL(Node * head) {
	Node * prev = NULL, * cur = head;

	while (cur) {
		Node * temp = cur->next;
		cur->next = prev;
		prev = cur;
		cur = temp;
	}
	return prev;
}

vector<int> nextLargerNodes(Node * head) {
	head = reverse_LL(head);

	stack<int> s;
	vector<int> ans;

	Node * cur = head;

	while (cur) {

		if (s.size()) {
			if (s.top() > cur->data) {
				ans.push_back(s.top());
			} else {
				while (s.size() && s.top() <= cur->data) {
					s.pop();
				}
				if (s.size()) {
					ans.push_back(s.top());
				} else {
					ans.push_back(0);
				}
			}
		} else {
			ans.push_back(0);
		}

		s.push(cur->data);
		cur = cur->next;
	}

	head = reverse_LL(head);

	reverse(ans.begin(), ans.end());

	return ans;
}

int main() {
	int n;
	cin >> n;

	Node * head = takeInput(n);

	vector<int> ans = nextLargerNodes(head);

	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}

	delete head;

	return 0;
}