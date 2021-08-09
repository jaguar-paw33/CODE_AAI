#include<bits/stdc++.h>
using namespace std;

bool is_odd(int n) {
	return n & 1;
}

int main() {
	int n;
	cin >> n;

	cout << is_odd(n) << endl;

	return 0;
}