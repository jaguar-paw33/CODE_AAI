#include <bits/stdc++.h>
// #include "stack_using_dynamic_array.h"
#include "stack_using_linked_list.h"
using namespace std;


int main() {
	Stack<char> s;
	s.push(97);
	s.push(98);
	s.push(99);
	s.push(100);
	s.push(101);
	s.push(102);
	s.push(103);
	s.push(104);


	while (!s.isEmpty()) {
		cout << "Size : " << s.getSize();
		cout << " Top : " << s.top() << " ";
		cout << " Remove Top : " << s.pop() << endl;
	}

	cout << endl << s.top() << endl;
	cout << s.pop();

	return 0;
}