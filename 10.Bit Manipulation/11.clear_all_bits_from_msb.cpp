#include<bits/stdc++.h>
using namespace std;

int clear_all_bits_from_msb_to_i(int n, int i) {
	int mask = (1 << i) - 1;
	return n & mask;
}

int main() {
	int n, i;
	cin >> n >> i;

	cout << clear_all_bits_from_msb_to_i(n, i) << endl; // MSB(Most Significant Bit) is the Left Most Bit

	return 0;
}