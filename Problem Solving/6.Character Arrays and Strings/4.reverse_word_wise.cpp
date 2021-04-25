/*

Reverse the given string word wise. That is, the last word in given string should come at 1st place, last second word at 2nd place and so on. Individual words should remain as it is.

Input format :
String in a single line

Output format :
Word wise reversed string in a single line

Constraints :
0 <= |S| <= 10^7
where |S| represents the length of string, S.

Sample Input 1:
Welcome to Coding Ninjas
Sample Output 1:
Ninjas Coding to Welcome

Sample Input 2:
Always indent your code
Sample Output 2:
code your indent Always

*/

#include<bits/stdc++.h>
using namespace std;

void rev(string & s, int si, int ei) {
	for (int i = si, j = ei; i < j; i++, j--) {
		char temp = s[i];
		s[i] = s[j];
		s[j] = temp;
	}
}

void reverse_word_wise(string & s) {

	rev(s, 0, s.size() - 1);

	for (int i = 0, j = 0; j <= s.size(); j++) {
		if (s[j] == ' ' || s[j] == '\0') {
			rev(s, i, j - 1);
			i = j + 1;
		}
	}
}

int main() {
	string s;

	getline(cin, s);

	reverse_word_wise(s);

	cout << s << endl;

	return 0;
}