/*

Given a number N, find its square root. You need to find and print only the integral part of square root of N.
For eg. if number given is 18, answer is 4.
Input format :
Integer N
Output Format :
Square root of N (integer part only)
Constraints :
0 <= N <= 10^8
Sample Input 1 :
10
Sample Output 1 :
3
Sample Input 2 :
4
Sample Output 2 :
2

*/


#include<iostream>
using namespace std;

int int_sqrt(int n) {
	int i;
	for (i = 1; i <= n / 2; i++) {
		if (i * i == n)
			return i;
		else if (i * i > n)
			break;
	}
	return i - 1;
}

int main() {
	int n;
	cin >> n;

	cout << int_sqrt(n) << endl;

	return 0;
}