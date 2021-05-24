#include<bits/stdc++.h>
// #include"min_priority_queue.h"
#include"max_priority_queue.h"
using namespace std;


int main() {
	PriorityQueue pq;
	pq.insert(10);
	pq.insert(20);
	pq.insert(30);
	pq.insert(40);
	pq.insert(50);
	pq.insert(60);
	pq.insert(70);
	// while (!pq.isEmpty()) {
	// 	cout << pq.getMin() << endl;
	// 	cout << pq.removeMin() << endl;
	// }
	while (!pq.isEmpty()) {
		cout << pq.getMax() << endl;
		cout << pq.removeMax() << endl;
	}
	return 0;
}