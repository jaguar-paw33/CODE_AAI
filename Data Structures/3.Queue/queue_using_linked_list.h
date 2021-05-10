#include<bits/stdc++.h>
using namespace std;

template<typename T>
class Node {
public:
	T data;
	Node<T> * next;

	Node(T data) {
		this->data = data;
		this->next = NULL;
	}
};


template<typename W>
class Queue {

	Node<W> * head;
	Node<W> * tail;
	int size;

public:

	Queue() {
		head = NULL;
		tail = NULL;
		size = 0;
	}

	bool isEmpty() {
		return size == 0;
	}

	int getSize() {
		return size;
	}

	void enqueue(W value) {
		Node<W> * newNode = new Node<W> (value);

		if (!head) {
			head = newNode;
			tail = newNode;
		} else {
			tail->next = newNode;
			tail = tail->next;
		}
		size++;
	}

	W dequeue() {
		if (isEmpty()) {
			cout << "Queue is Empty" << endl;
			return 0;
		}
		Node<W> * temp = head;
		head = head->next;
		size--;
		W ans = temp->data;
		temp->next = NULL;
		delete temp;
		return ans;
	}

	W front() {
		if (isEmpty()) {
			cout << "Queue is Empty" << endl;
			return 0;
		}
		return head->data;
	}
};