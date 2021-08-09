/*

You are given an integer Ni. You need to make first set bit of binary representation of N to 0 and return the updated N.
Counting of bits start from 0 from right to left.

*/

#include<bits/stdc++.h>
using namespace std;

int first_set_bit_bit_off(int n) {
	return n & (n - 1);
}

int main() {
	int n;
	cin >> n;

	cout << first_set_bit_bit_off(n) << endl;

	return 0;
}