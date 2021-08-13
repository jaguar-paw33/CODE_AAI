#include<bits/stdc++.h>
using namespace std;

void insert(stack<int> & s, int a) { // This is same as creating a temp stack but using recursion
	if (!s.size()) {
		s.push(a);
		return;
	}
	int t = s.top();
	s.pop();
	insert(s, a);
	s.push(t);
}

void reverse(stack<int> & s) {
	if (!s.size())
		return;

	int a = s.top();
	s.pop();

	reverse(s);

	insert(s, a);
}

int main() {
	int n;
	cin >> n;

	stack<int> s;
	int v;

	while (n--) {
		cin >> v;
		s.push(v);
	}

	reverse(s);

	while (!s.empty()) {
		cout << s.top() << " ";
		s.pop();
	}

	return 0;
}

