#include <bits/stdc++.h>
// #include "queue_using_dynamic_array.h"
#include "queue_using_linked_list.h"
using namespace std;


int main() {
	Queue<char> q;

	q.enqueue(97);
	q.enqueue(98);
	q.enqueue(99);
	q.enqueue(100);
	q.enqueue(101);
	q.enqueue(102);
	q.enqueue(103);
	q.enqueue(104);


	while (!q.isEmpty()) {
		cout << "Size : " << q.getSize() << " ";
		cout << "Front : " << q.front() << " ";
		cout << "Dequeue : " << q.dequeue() << endl;
	}

	cout << endl << q.front() << endl;
	cout << endl << q.dequeue() << endl;

	return 0;
}
