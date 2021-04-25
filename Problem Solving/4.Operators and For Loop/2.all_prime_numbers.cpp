/*

Given an integer N, print all the prime numbers that lie in the range 2 to N (both inclusive).
Print the prime numbers in different lines.
Input Format :
Integer N
Output Format :
Prime numbers in different lines
Constraints :
1 <= N <= 100
Sample Input 1:
9
Sample Output 1:
2
3
5
7
Sample Input 2:
20
Sample Output 2:
2
3
5
7
11
13
17
19

*/

#include<iostream>
#include<cmath>
using namespace std;

bool isPrime(int n) {
	bool prime = true;

	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0)
			return prime = false;
	}
	return prime;
}

void print_all_prime(int n) {
	for (int i = 2; i <= n; i++) {
		if (isPrime(i))
			cout << i << endl;
	}
}

int main() {
	int n;
	cin >> n;

	print_all_prime(n);

	return 0;
}