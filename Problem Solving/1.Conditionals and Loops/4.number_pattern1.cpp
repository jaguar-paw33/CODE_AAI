/*

Print the following pattern

Pattern for N = 4
1
23
345
4567

Input Format :
N (Total no. of rows)

Output Format :
Pattern in N lines

Sample Input 1 :
3

Sample Output 1 :
1
23
345

*/

#include<iostream>
using namespace std;

void pattern(int n) {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			cout << j + i - 1;
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