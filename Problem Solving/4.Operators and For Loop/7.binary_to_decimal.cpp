/*

Given a binary number as an integer N, convert it into decimal and print.
Input format :
An integer N in the Binary Format
Output format :
Corresponding Decimal number (as integer)
Constraints :
0 <= N <= 10^9
Sample Input 1 :
1100
Sample Output 1 :
12
Sample Input 2 :
111
Sample Output 2 :
7

*/

#include<iostream>
using namespace std;

int bin_to_dec(int n) {
	int exp = 1;
	int ans = 0;
	while (n) {
		ans += (n % 10) * exp;
		exp *= 2;
		n /= 10;
	}
	return ans;
}

int main() {
	int n;
	cin >> n;

	cout << bin_to_dec(n) << endl;

	return 0;
}