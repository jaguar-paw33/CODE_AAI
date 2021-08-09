/*

Given the head of a singly linked list and an integer k, split the linked list into k consecutive linked list parts.

The length of each part should be as equal as possible: no two parts should have a size differing by more than one. This may lead to some parts being null.

The parts should be in the order of occurrence in the input list, and parts occurring earlier should always have a size greater than or equal to parts occurring later.

Return an array of the k parts.



Example 1:


Input: head = [1,2,3], k = 5
Output: [[1],[2],[3],[],[]]
Explanation:
The first element output[0] has output[0].val = 1, output[0].next = null.
The last element output[4] is null, but its string representation as a ListNode is [].
Example 2:


Input: head = [1,2,3,4,5,6,7,8,9,10], k = 3
Output: [[1,2,3,4],[5,6,7],[8,9,10]]
Explanation:
The input has been split into consecutive parts with size difference at most 1, and earlier parts are a larger size than the later parts.


Constraints:

The number of nodes in the list is in the range [0, 1000].
0 <= Node.val <= 1000
1 <= k <= 50

*/

#include<bits/stdc++.h>
#include"singly_linked_list.h"
using namespace std;

int length(Node * head) {
	int len = 0;
	Node * cur = head;
	while (cur) {
		len++;
		cur = cur->next;
	}
	return len;
}

vector<Node *> split_in_k(Node * head, int k) {

	vector<Node *> ans;

	Node * cur = head;
	int len = length(head);

	if (len <= k) {
		while (cur) {
			Node * temp = cur;
			cur = cur->next;
			temp->next = NULL;
			ans.push_back(temp);
			k--;
		}
		while (k) {
			ans.push_back(NULL);
			k--;
		}
	} else {
		int part_size = len / k;
		int part_additional = len % k;

		while (k--) {

			Node * temp = cur;
			int count = part_size;

			if (part_additional) {
				part_additional--;
				count += 1;
			}

			while (--count) {
				cur = cur->next;

			}
			Node * c = cur;
			cur = cur->next;
			c->next = NULL;
			ans.push_back(temp);
		}
	}

	return ans;
}

int main() {
	int n;
	cin >> n;
	Node * head = takeInput(n);
	int k;
	cin >> k;
	vector<Node *> ans = split_in_k(head, k);

	for (int i = 0; i < ans.size(); i++) {
		Node * h = ans[i];
		while (h) {
			cout << h->data << " ";
			h = h->next;
		}
		cout << endl;
	}

	delete head;
	return 0;
}