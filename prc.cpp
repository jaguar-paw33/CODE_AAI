#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
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

	~Node() {
		delete next;
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
	return head;
}

void printLL(Node * head) {
	Node * temp = head;
	while (temp) {
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}


pair<Node * , Node *> linked_lists_union_and_intersection(Node * h1, Node * h2) {
	unordered_map<int, int> m;

	Node * hu = NULL, * tu = NULL;
	Node * hi = NULL, * ti = NULL;

	while (h2) {
		m[h2->data]++;
		if (!hu) {
			hu = h2;
			tu = h2;
		} else {
			tu->next = h2;
			tu = h2;
		}
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
			m[h1->data]--;
		} else {
			if (!hi) {
				hi = h1;
				ti = h1;
			} else {
				ti->next = h1;
				ti = h1;
			}
		}
		h1 = h1->next;
	}

	if (hu) {
		tu -> next = NULL;
	}

	if (hi) {
		ti -> next = NULL;
	}

	return pair<Node *, Node *>(hu, hi);
}

Node * middle(Node * h) {
	Node * slow = h, * fast = h->next;

	while (fast && fast->next) {
		slow = slow->next;
		fast = fast->next;
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
	mid = merge_sort(temp);

	h = merge(h, mid);

	return h;
}


int main() {
	int n1, n2;
	cin >> n1 >> n2;

	Node * h1 = takeInput(n1);
	Node * h2 = takeInput(n2);

	pair<Node *, Node *> p = linked_lists_union_and_intersection(h1, h2);

	p.first = merge_sort(p.first);
	p.second = merge_sort(p.second);

	printLL(p.first);
	printLL(p.second);

	return 0;
}