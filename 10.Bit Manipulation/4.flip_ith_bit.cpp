#include<bits/stdc++.h>
using namespace std;

int flip_ith_bit(int n, int i) {
	int mask = 1 << i;
	return n ^ mask;
}

int main() {
	int n, i;

	cin >> n >> i;

	cout << flip_ith_bit(n, i) << endl;

	return 0;
}