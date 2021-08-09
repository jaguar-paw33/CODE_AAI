#include<bits/stdc++.h>
using namespace std;

int first_set_bit_index(int n) {
	int set_bit_num = n & (~(n - 1));
	return log2(set_bit_num); // Add 1 while considering the right most bit as index 1
}

int main() {
	int n;
	cin >> n;

	cout << first_set_bit(n) << endl;

	return 0;
}