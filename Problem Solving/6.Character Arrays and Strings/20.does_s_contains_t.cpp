/*

Given two string s and t, write a function to check if s contains all characters of t (in the same order as they are in string t).
Return true or false.
Do it recursively.
E.g. : s = “abchjsgsuohhdhyrikkknddg” contains all characters of t=”coding” in the same order. So function will return true.
Input Format :
Line 1 : String s
Line 2 : String t
Output Format :
true or false
Sample Input 1 :
abchjsgsuohhdhyrikkknddg
coding
Sample Output 1 :
true
Sample Input 2 :
abcde
aeb
Sample Output 2 :
false

*/

#include<bits/stdc++.h>
using namespace std;

bool s_contains_t(string s, string t) {
	if (!s.size() && t.size()) {
		return false;
	} else if (!t.size()) {
		return true;
	}

	if (s[0] == t[0])
		return s_contains_t(s.substr(1), t.substr(1));
	else
		return s_contains_t(s, t.substr(1));
}

int main() {
	string s, t;
	cin >> s;
	cin >> t;

	cout << (s_contains_t(s, t) ? "true" : "false") << endl;

	return 0;
}