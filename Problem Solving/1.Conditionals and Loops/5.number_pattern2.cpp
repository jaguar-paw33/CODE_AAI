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

Sample Input :
5

Sample Output :
    1
   23
  345
 4567
56789

 */



#include<iostream>
using namespace std;

void pattern(int n) {
	for (int i = 1; i <= n; i++) {
		for (int j = i; j < n; j++) {
			cout << " ";
		}
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