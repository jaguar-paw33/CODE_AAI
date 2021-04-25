/*

Print the following pattern for the given number of rows.
Note: N is always odd.

Input format :
N (Total no. of rows and can only be odd)

Output format :
Pattern in N lines

Constraints :
1 <= N <= 49

Sample Input 1:
5
Sample Output 1:
  *
 ***
*****
 ***
  *

Sample Input 2:
3

Sample Output 2:
  *
 ***
  *

 */


#include<iostream>
using namespace std;

void pattern(int n) {
	for (int i = 1; i <= n / 2 + 1; i++) {
		for (int j = 1; j <= n / 2 + 1 - i; j++) {
			cout << " ";
		}
		for (int j = 1; j <= i; j++) {
			cout << "*";
		}
		for (int j = 1; j < i; j++) {
			cout << "*";
		}
		cout << endl;
	}

	for (int i = 1; i <= n / 2; i++) {
		for (int j = 1; j <= i; j++) {
			cout << " ";
		}
		for (int j = 1; j <= n / 2 - i + 1; j++) {
			cout << "*";
		}
		for (int j = 1; j < n / 2 - i + 1; j++) {
			cout << "*";
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
