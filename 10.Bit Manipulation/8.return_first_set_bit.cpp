/*

You are given an integer N. You need to return an integer M, in which only one bit is set which at position of lowest set bit of N (from right to left).

*/


#include<bits/stdc++.h>
using namespace std;

int first_set_bit(int n) {
	int mask = ~(n - 1);
	return n & mask;
}

int main() {
	int n;
	cin >> n;

	cout << first_set_bit(n) << endl;

	return 0;
}