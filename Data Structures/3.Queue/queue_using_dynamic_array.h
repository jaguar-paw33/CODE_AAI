#include<bits/stdc++.h>
using namespace std;

template<typename T>
class Queue {

	T * arr;
	int capacity;
	int first_index;
	int next_index;
	int size = 0;

public:

	Queue() {
		capacity = 5;
		arr = new T [5];
		first_index = -1;
		next_index = 0;
	}

	bool isEmpty() {
		return size == 0;
	}

	int getSize() {
		return size;
	}

	void enqueue(T value) {

		if (size == capacity) {
			T * temp = arr;
			int oldCapacity = capacity;
			capacity *= 2;
			arr = new T[capacity];
			int j = 0;
			for (int i = first_index; i < oldCapacity; i++) {
				arr[j++] = temp[i];
			}
			for (int i = 0; i < first_index; i++) {
				arr[j++] = temp[i];
			}
			first_index = 0;
			next_index = oldCapacity;
			delete [] temp;
		}
		if (first_index == -1) {
			first_index = 0;
		}
		arr[(next_index) % capacity] = value;
		next_index = (next_index) % capacity + 1;
		size++;
	}

	T dequeue() {
		if (isEmpty()) {
			cout << "Queue is Empty" << endl;
			return 0;
		}
		size--;
		return arr[first_index++];
	}

	T front() {
		if (isEmpty()) {
			cout << "Queue is Empty" << endl;
			return 0;
		}
		return arr[first_index];
	}
};
