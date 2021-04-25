/*

Assume that the value of a = 1, b = 2, c = 3, ... , z = 26. You are given a numeric string S. Write a program to print the list of all possible codes that can be generated from the given string.

Note : The order of codes are not important. Just print them in different lines.

Input format :
A numeric string S

Output Format :
All possible codes in different lines

Constraints :
1 <= Length of String S <= 10

Sample Input:
1123

Sample Output:
aabc
kbc
alc
aaw
kw

*/

#include<bits/stdc++.h>
using namespace std;

void print_all_codes(string s, string output) {
	if (!s.size()) {
		cout << output << endl;
		return;
	}

	int d1 = s[0] - 48;
	int d2 = 0;
	if (s.size() > 1) {
		d2 = (s[0] - 48) * 10 + s[1] - 48;
	}

	char c1 = char(d1 + 96);
	char c2 = '\0';

	if (d2 >= 10 && d2 <= 26) {
		c2 = char(d2 + 96);
	}

	print_all_codes(s.substr(1), output + c1);

	if (c2 != '\0') {
		print_all_codes(s.substr(2), output + c2);
	}
}

int main() {
	string s;
	cin >> s;

	print_all_codes(s, "");

	return 0;
}