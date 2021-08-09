#include<bits/stdc++.h>
#include"singly_linked_list.h"
using namespace std;

Node * middle(Node * h) {
	Node * slow = h, * fast = h->next;

	while (fast && fast->next) {
		slow = slow->next;
		fast = fast->next->next;
	}

	return slow;
}

Node * merge(Node * h1, Node * h2) {
	Node * h = NULL, * t = NULL;

	while (h1 && h2) {
		if (h1->data < h2->data) {
			if (!h) {
				h = h1;
				t = h1;
			} else {
				t->next = h1;
				t = h1;
			}
			h1 = h1->next;
		} else {
			if (!h) {
				h = h2;
				t = h2;
			} else {
				t->next = h2;
				t = h2;
			}
			h2 = h2->next;
		}
	}

	while (h1) {
		if (!h) {
			h = h1;
			t = h1;
		} else {
			t->next = h1;
			t = h1;
		}
		h1 = h1->next;
	}

	while (h2) {
		if (!h) {
			h = h2;
			t = h2;
		} else {
			t->next = h2;
			t = h2;
		}
		h2 = h2->next;
	}

	return h;
}

Node * merge_sort(Node * h) {

	if (!h || !h->next) {
		return h;
	}

	Node * mid = middle(h);
	Node * temp = mid->next;
	mid->next = NULL;

	h = merge_sort(h);
	temp = merge_sort(temp);

	h = merge(h, temp);

	return h;
}

Node * remove_duplicates(Node * h) {
	if (!h || !h->next)
		return h;

	Node * prev = h, * cur = h->next;
	while (cur) {
		if (cur->data == prev->data) {
			Node * t = cur;
			cur = cur->next;
			prev->next = cur;
			t->next = NULL;
			delete t;
		} else {
			prev = cur;
			cur = cur->next;
		}
	}

	return h;
}

// Sorting Approach (Time Complexity - O(n+m) and Space Complexity - O(logn + logm) if using recursive merge sort else O(1) if using iterative merge sort), where n is the size of first linked list and m is the size of the second linked list
pair < Node *, Node *> linked_lists_union_and_intersection(Node * h1, Node * h2) {
	unordered_map<int, int> m;

	Node * hu = NULL, * tu = NULL;
	Node * hi = NULL, * ti = NULL;

	h1 = merge_sort(h1);
	h2 = merge_sort(h2);

	// Remove Duplicate Elements
	h1 = remove_duplicates(h1);
	h2 = remove_duplicates(h2);

	while (h1 && h2) {
		if (h1->data < h2->data) {

			if (!hu) {
				hu = h1;
				tu = h1;
			} else {
				tu->next = h1;
				tu = h1;
			}

			h1 = h1->next;

		} else if (h1->data > h2->data) {

			if (!hu) {
				hu = h2;
				tu = h2;
			} else {
				tu->next = h2;
				tu = h2;
			}

			h2 = h2->next;

		} else {

			if (!hu) {
				hu = h2;
				tu = h2;
			} else {
				tu->next = h2;
				tu = h2;
			}

			if (!hi) {
				hi = h1;
				ti = h1;
			} else {
				ti->next = h1;
				ti = h1;
			}

			h1 = h1->next;
			h2 = h2->next;
		}

	}

	while (h1) {
		if (!hu) {
			hu = h1;
			tu = h1;
		} else {
			tu->next = h1;
			tu = h1;
		}
		h1 = h1->next;
	}

	while (h2) {
		if (!hu) {
			hu = h2;
			tu = h2;
		} else {
			tu->next = h2;
			tu = h2;
		}

		h2 = h2->next;
	}

	if (hu) {
		tu->next = NULL;
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

	pair<Node * , Node *> p = linked_lists_union_and_intersection(h1, h2);

	printLL(p.first);
	printLL(p.second);

	return 0;
}