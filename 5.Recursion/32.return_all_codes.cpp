/*

Assume that the value of a = 1, b = 2, c = 3, ... , z = 26. You are given a numeric string S. Write a program to return the list of all possible codes that can be generated from the given string.

Note : The order of codes are not important. And input string does not contain 0s.

Input format :
A numeric string

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

int return_codes(string s, string output[]) {
	if (!s.size()) {
		output[0] = "";
		return 1;
	}

	string output1[10000];
	string output2[10000];

	char code1 = char(s[0] - 48 + 96);
	char code2 = '\0';

	int d2 = 0;

	if (s.size() > 1) {
		d2 = (s[0] - 48) * 10 + s[1] - 48;
	}

	if (d2 >= 10 && d2 <= 26) {
		code2 = char(d2 + 96);
	}

	int size1 = return_codes(s.substr(1), output1);
	int size2 = 0;

	if (code2 != '\0') {
		size2 = return_codes(s.substr(2), output2);
	}

	for (int i = 0; i < size1; i++) {
		output[i] = code1 + output1[i];
	}

	for (int i = 0; i < size2; i++) {
		output[i + size1] = code2 + output2[i];
	}

	return (size1 + size2);
}


int main() {
	string s;
	cin >> s;

	string output[10000];

	int size = return_codes(s, output);

	for (int i = 0; i < size; i++) {
		cout << output[i] << endl;
	}

	return 0;
}