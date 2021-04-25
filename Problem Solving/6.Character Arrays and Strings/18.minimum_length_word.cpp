/*

Given a string S (that can contain multiple words), you need to find the word which has minimum length.

Note : If multiple words are of same length, then answer will be first minimum length word in the string.
Words are seperated by single space only.

Input Format :
String S

Output Format :
Minimum length word

Constraints :
1 <= Length of String S <= 10^5

Sample Input 1 :
this is test string
Sample Output 1 :
is

Sample Input 2 :
abc de ghihjk a uvw h j
Sample Output 2 :
a

*/

#include<bits/stdc++.h>
using namespace std;

string max_len_word(string & s) {
	string word = "";
	int max_len = INT_MAX;

	for (int i = 0, j = 0; i <= s.size(); i++) {
		if (s[i] == ' ' || s[i] == '\0') {
			if (max_len > (i - j)) {
				max_len = i - j;
				word = s.substr(j, i - j);
			}
			j = i + 1;
		}
	}

	return word;
}

int main() {
	string s;
	getline(cin, s);

	cout << max_len_word(s) << endl;

	return 0;
}