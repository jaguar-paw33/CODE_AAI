#include<bits/stdc++.h>
using namespace std;

int set_ith_bit(int n, int i) {
	int mask = 1 << i;
	return n ^ mask;
}

int main() {
	int n;
	int i;

	cin >> n >> i;

	cout << set_ith_bit(n, i) << endl;

	return 0;
}