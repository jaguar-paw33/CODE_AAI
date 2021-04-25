/*

Given an input string S that contains multiple words, you need to remove all the spaces present in the input string.
There can be multiple spaces present after any word.

Input Format :
String S

Output Format :
Updated string

Constraints :
1 <= Length of string S <= 10^6

Sample Input :
abc def g hi
Sample Output :
abcdefghi

*/

#include<bits/stdc++.h>
using namespace std;

void trim_spaces(string & s) {
	int i, j;
	for ( i = 0, j = 0; i < s.size(); i++) {
		if (s[i] != ' ') {
			s[j++] = s[i];
		}
	}
	s[j] = '\0';
}

int main() {
	string s;
	getline(cin, s);

	trim_spaces(s);

	cout << s << endl;

	return 0;
}