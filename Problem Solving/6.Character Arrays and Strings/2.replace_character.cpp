/*

Given an input string S and two characters c1 and c2, you need to replace every occurrence of character c1 with character c2 in the given string.

Input Format :

Line 1 : Input String S
Line 2 : Character c1 and c2 (separated by space)

Output Format :

Updated string

Constraints :
1 <= Length of String S <= 10^6

Sample Input :
abacd
a x
Sample Output :
xbxcd

*/

#include<bits/stdc++.h>
using namespace std;

void replace_c1_with_c2(string & s, char c1, char c2) {
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == c1)
			s[i] = c2;
	}
}

int main() {

	string s;
	getline(cin, s);

	char c1, c2;
	cin >> c1 >> c2;

	replace_c1_with_c2(s, c1, c2);

	cout << s << endl;

	return 0;
}