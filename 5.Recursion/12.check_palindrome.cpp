/*

Check whether a given String S is a palindrome using recursion. Return true or false.

Input Format :
String S

Output Format :
'true' or 'false'

Constraints :
0 <= |S| <= 1000
where |S| represents length of string S.

Sample Input 1 :
racecar
Sample Output 1:
true

Sample Input 2 :
ninja
Sample Output 2:
false

*/


#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string s, int si, int ei) {

	if (si >= ei)
		return true;

	if (s[si] != s[ei])
		return false;

	return isPalindrome(s, si + 1, ei - 1);
}

int main() {

	string s;
	getline(cin, s);

	cout << (isPalindrome(s, 0, s.size() - 1) ? "true" : "false") << endl;

	return 0;
}