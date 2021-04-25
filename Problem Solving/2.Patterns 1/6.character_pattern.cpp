/*

Print the following pattern for the given N number of rows.

Pattern for N = 4
A
BC
CDE
DEFG

Input format :
Integer N (Total no. of rows)

Output format :
Pattern in N lines

Constraints
0 <= N <= 13

Sample Input 1:
5
Sample Output 1:
A
BC
CDE
DEFG
EFGHI

Sample Input 2:
6
Sample Output 2:
A
BC
CDE
DEFG
EFGHI
FGHIJK

*/


#include<iostream>
using namespace std;

void pattern(int n) {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			cout << char('A' + i + j - 2);
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