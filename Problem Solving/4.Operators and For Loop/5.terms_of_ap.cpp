/*

Write a program to print first x terms of the series 3N + 2 which are not multiples of 4.
Input format :
Integer x
Output format :
Terms of series (separated by space)
Constraints :
1 <= x <= 1,000
Sample Input 1 :
10
Sample Output 1 :
5 11 14 17 23 26 29 35 38 41
Sample Input 2 :
4
Sample Output 2 :
5 11 14 17

*/

#include<iostream>
using namespace std;

void first_x(int x) {
	for (int i = 1, j = 1; i <= x; j++) {
		int term = 3 * j + 2;

		if (term % 4)
		{
			i++;
			cout << term << " ";
		}
	}
}

int main() {
	int x;
	cin >> x;

	first_x(x);

	return 0;
}