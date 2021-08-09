#include<bits/stdc++.h>
#include"singly_linked_list.h"
using namespace std;

// Hashing Approach (Time Complexity - O(n+m) and Space Complexity - O(m)), where n is the size of first linked list and m is the size of the second linked list
pair<Node *, Node *> linked_lists_union_and_intersection(Node * h1, Node * h2) {
	unordered_map<int, int> m;

	Node * hu = NULL, * tu = NULL;
	Node * hi = NULL, * ti = NULL;

	while (h2) {

		if (!m[h2->data]) {
			if (!hu) {
				hu = h2;
				tu = h2;
			} else {
				tu->next = h2;
				tu = h2;
			}
		}

		m[h2->data] = 1;

		h2 = h2->next;
	}

	while (h1) {
		if (!m[h1->data]) {

			if (!hu) {
				hu = h1;
				tu = h1;
			} else {
				tu->next = h1;
				tu = h1;
			}

		} else if (m[h1->data] == 1) {
			if (!hi) {
				hi = h1;
				ti = h1;
			} else {
				ti->next = h1;
				ti = h1;
			}
		}

		m[h1->data] = -1;
		h1 = h1->next;
	}

	if (hu) {
		tu -> next = NULL;
	}

	if (hi) {
		ti->next = NULL;
	}

	return pair<Node *, Node *> (hu, hi);
}

int main() {
	int n1, n2;
	cin >> n1 >> n2;

	Node * h1 = takeInput(n1);
	Node * h2 = takeInput(n2);

	pair<Node *, Node *> p = linked_lists_union_and_intersection(h1, h2);

	printLL(p.first);
	printLL(p.second);

	return 0;
}