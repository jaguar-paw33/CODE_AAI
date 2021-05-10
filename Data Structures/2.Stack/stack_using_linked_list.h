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
class Stack {

	Node<W> * head;
	int size;

public:

	Stack() {
		head = NULL;
		size = 0;
	}

	bool isEmpty() {
		return size == 0;
	}

	int getSize() {
		return size;
	}

	void push(W data) {
		Node<W> * newNode = new Node<W>(data);
		if (!head) {
			head = newNode;
		}
		else {
			newNode->next = head;
			head = newNode;
		}
		size++;
	}

	W pop() {
		if (isEmpty()) {
			cout << "Stack is Empty" << endl;
			return 0;
		}
		Node<W> * temp = head;
		head = head->next;
		temp->next = NULL;
		W ans = temp->data;
		delete temp;
		size--;
		return ans;
	}

	W top() {
		if (isEmpty()) {
			cout << "Stack is Empty" << endl;
			return 0;
		}
		return head->data;
	}
};