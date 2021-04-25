/*

Given a string, compute recursively a new string where all 'x' chars have been removed.

Input format :
String S

Output format :
Modified String

Constraints :
1 <= |S| <= 10^3
where |S| represents the length of string S.

Sample Input 1 :
xaxb
Sample Output 1:
ab

Sample Input 2 :
abc
Sample Output 2:
abc

Sample Input 3 :
xx
Sample Output 3:

*/

#include<bits/stdc++.h>
using namespace std;

void removex(char * input) {
	if (strlen(input) <= 0)
		return;

	removex(input + 1);

	if (input[0] == 'x') {
		for (int i = 1; i <= strlen(input); i++)
			input[i - 1] = input[i];
	}
}

int main() {
	char input[1000];
	cin >> input;

	removex(input);

	cout << input << endl;

	return 0;
}