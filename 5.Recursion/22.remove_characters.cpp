/*

Given a string S, remove consecutive duplicates from it recursively.

Input Format :
String S

Output Format :
Output string

Constraints :
1 <= |S| <= 10^3
where |S| represents the length of string

Sample Input 1 :
aabccba
Sample Output 1 :
abcba

Sample Input 2 :
xxxyyyzwwzzz
Sample Output 2 :
xyzwz

*/

#include<bits/stdc++.h>
using namespace std;

void remove_consec_duplicates(char * input) {
	if (input[0] == '\0')
		return;

	while (input[0] == input[1]) {
		int i;
		for (i = 1; input[i] != '\0'; i++) {
			input[i - 1] = input[i];
		}
		input[i - 1] = '\0';
	}
	remove_consec_duplicates(input + 1);
}

int main() {
	char input[1000];
	cin >> input;

	remove_consec_duplicates(input);

	cout << input << endl;

	return 0;
}