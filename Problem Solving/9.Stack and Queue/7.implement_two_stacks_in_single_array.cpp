#include<bits/stdc++.h>
using namespace std;

class Stack {
	int top1;
	int top2;
	int * arr;
public:
	Stack() {
		arr = new int [10];
		top1 = 0;
		top2 = 9;
	}

	void push(int a, int n) {
		if (n == 1) {
			if (top1 > top2) {
				cout << "Stack 1 is Full" << endl;
				return;
			}
			arr[top1++] = a;
		} else if (n == 2) {
			if (top1 > top2) {
				cout << "Stack 2 is Full" << endl;
				return;
			}
			arr[top2--] = a;
		}
	}

	int top(int n) {
		if (n == 1) {
			if (top1 == 0) {
				cout << "Stack 1 is Empty" << endl;
				return -1;
			}
			return arr[top1 - 1];
		} else if (n == 2) {
			if (top2 == 999) {
				cout << "Stack 2 is Empty" << endl;
				return -1;
			}
			return arr[top2 + 1];
		}
		return -1;
	}

	void pop(int n) {
		if (n == 1) {
			if (top1 == 0) {
				cout << "Stack 1 is Empty" << endl;
				return;
			}
			top1--;
		} else if (n == 2) {
			if (top2 == 999) {
				cout << "Stack 2 is Empty" << endl;
				return;
			}
			top2++;
		}
	}
};

int main() {
	Stack s;
	s.push(1, 1);
	s.push(10, 2);
	s.push(2, 1);
	s.push(3, 1);
	s.push(4, 1);
	s.push(9, 2);
	s.push(5, 1);
	s.push(8, 2);
	s.push(7, 2);
	s.push(6, 2);
	s.push(6, 2);
	cout << s.top(1) << endl;
	s.pop(1);
	cout << s.top(1) << endl;
	s.pop(1);
	cout << s.top(1) << endl;
	s.pop(1);
	cout << s.top(1) << endl;
	s.pop(1);
	cout << s.top(1) << endl;
	s.pop(1);
	cout << s.top(1) << endl;
	s.pop(1);
	cout << s.top(1) << endl;
	s.pop(1);
	cout << s.top(1) << endl;
	s.pop(1);
}