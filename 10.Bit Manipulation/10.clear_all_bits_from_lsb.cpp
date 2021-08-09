#include<bits/stdc++.h>
using namespace std;

int clear_from_i_to_lsb(int n, int i) {
	int mask = ~((1 << (i + 1)) - 1);
	return n & mask;
}

int main() {
	int n, i;
	cin >> n >> i;


	cout << clear_from_i_to_lsb(n, i) << endl; // lsb - Least Significant Bit (Rightmost Bit)

	return 0;
}