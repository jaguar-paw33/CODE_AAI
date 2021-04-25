// Euclid's Algorthm to compute GCD of 2 Numbers


#include<iostream>
using namespace std;

int main() {

	int m, n;
	cin >> m >> n;
	if (!m || !n) {
		cout << "GCD : " << 0 << endl;
		return 0;
	}
	while (m != n) {
		if (m > n) {
			m -= n;
		} else {
			n -= m;
		}
	}

	cout << "GCD : " << m << endl;
	return 0;
}