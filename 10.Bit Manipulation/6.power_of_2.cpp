#include<bits/stdc++.h>
using namespace std;

bool is_power_of_2(int n) {
	int mask = n - 1;
	return (n & (n - 1)) == 0;
}

int main() {
	int n;
	cin >> n;

	cout << is_power_of_2(n) << endl;

	return 0;
}