#include<bits/stdc++.h>
using namespace std;

template<typename T>
class Stack {

	T * arr;
	int capacity;
	int next_index;

public:

	Stack<T>() {
		this->capacity = 5;
		arr = new T [5];
		next_index = 0;
	}

	bool isEmpty() {
		return next_index == 0;
	}

	int getSize() {
		return next_index;
	}

	void push(T value) {
		arr[next_index++] = value;

		if (next_index == capacity) {
			T * temp = arr;
			int oldCapacity = capacity;
			capacity *= 2;
			arr = new T [capacity];

			for (int i = 0; i < oldCapacity; i++) {
				arr[i] = temp[i];
			}
			delete [] temp;
		}
	}

	T pop() {
		if (isEmpty()) {
			cout << "Stack is Empty" << endl;
			return 0;
		}
		return arr[--next_index];
	}

	T top() {
		if (isEmpty()) {
			cout << "Stack is Empty" << endl;
			return 0;
		}
		return arr[next_index - 1];
	}
};