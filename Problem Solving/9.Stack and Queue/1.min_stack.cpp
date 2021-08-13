/*

Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

Implement the MinStack class:

MinStack() initializes the stack object.
void push(val) pushes the element val onto the stack.
void pop() removes the element on the top of the stack.
int top() gets the top element of the stack.
int getMin() retrieves the minimum element in the stack.


Example 1:

Input
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]

Output
[null,null,null,null,-3,null,0,-2]

Explanation
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin(); // return -3
minStack.pop();
minStack.top();    // return 0
minStack.getMin(); // return -2


Constraints:

-2^31 <= val <= 2^31 - 1
Methods pop, top and getMin operations will always be called on non-empty stacks.
At most 3 * 10^4 calls will be made to push, pop, top, and getMin.

Practise Problem Link - https://leetcode.com/problems/min-stack/

*/


#include<bits/stdc++.h>
using namespace std;

class MinStack {

	long * arr;
	int size;
	int next;
	long min_element;

public:
	MinStack() {
		size = 30001;
		arr = new long [size];
		next = 0;
	}

	void push(int val) {

		if (!next) {
			min_element = val;
			arr[next++] = val;
		} else if (min_element <= val) {
			arr[next++] = val;
		} else {
			arr[next++] = long(2) * val - min_element;
			min_element = val;
		}

	}

	void pop() {
		long top_element = arr[next-- - 1];
		if (top_element < min_element) {
			min_element = 2 * min_element - top_element;
		}
	}

	int top() {
		if (arr[next - 1] < min_element) {
			return min_element;
		} else {
			return arr[next - 1];
		}
	}

	int getMin() {
		return min_element;
	}
};


int main() {
	MinStack* obj = new MinStack();
	obj->push(3);
	obj->push(4);
	obj->push(2);
	obj->push(-1);
	obj->push(6);
	obj->push(1);

	obj->pop();

	cout << obj->getMin() << endl;

	return 0;
}
