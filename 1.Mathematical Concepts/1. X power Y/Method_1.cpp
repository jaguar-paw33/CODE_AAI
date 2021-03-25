
// Most suitable when we have a very large value of y

#include<iostream>
using namespace std;

long int power(long int  x, long int  y) {
	long int res = 1;
	while (y) {
		if (y % 2 == 0) {
			x *= x;
			y /= 2;
		} else {
			res *= x;
			y--;
		}
	}
	return res;
}


int main() {
	long int x, y;
	cin >> x >> y;
	cout << power(x, y) << endl;
	return 0;
}