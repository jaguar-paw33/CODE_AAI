/*

Print the following pattern
Pattern for N = 4

Input Format :
N (Total no. of rows)

Output Format :
Pattern in N lines

Constraints :
0 <= N <= 50

Sample Input 1 :
3
Sample Output 1 :
   *
  ***
 *****

Sample Input 2 :
4
Sample Output 2 :
    *
   ***
  *****
 *******

 */

#include<iostream>
using namespace std;

void pattern(int n) {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n - i; j++) {
			cout << " ";
		}
		for (int j = 1; j <= i; j++) {
			cout << "*";
		}
		for (int j = 1; j <= i - 1; j++) {
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