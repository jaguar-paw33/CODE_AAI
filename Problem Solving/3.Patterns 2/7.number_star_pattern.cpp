/*

Print the following pattern for given number of rows.
Input format :

Line 1 : N (Total number of rows)

Sample Input :
   5
Sample Output :
1234554321
1234**4321
123****321
12******21
1********1

*/

#include<iostream>
using namespace std;

void pattern(int n) {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n - i + 1; j++) {
			cout << j;
		}
		for (int j = n - i + 1; j < n; j++) {
			cout << "*";
		}
		for (int j = n - 1; j > n - i; j--) {
			cout << "*";
		}
		for (int j = n - i; j >= 0; j--) {
			cout << j + 1;
		}
		cout << endl;
	}
}

int main() {
	int n;
	cin >> n;

	pattern(n);

	return 0;
}