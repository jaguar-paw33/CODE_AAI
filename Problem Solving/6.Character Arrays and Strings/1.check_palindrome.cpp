/*

Given a string, determine if it is a palindrome, considering only alphanumeric characters.
Palindrome

A palindrome is a word, number, phrase, or other sequences of characters which read the same backwards and forwards.

Example:

If the input string happens to be, "malayalam" then as we see that this word can be read the same as forward and backwards, it is said to be a valid palindrome.

The expected output for this example will print, 'true'.
From that being said, you are required to return a boolean value from the function that has been asked to implement.

Input Format:

The first and only line of input contains a string without any leading and trailing spaces. All the characters in the string would be in lower case.
Output Format:

The only line of output prints either 'true' or 'false'.

Constraints:
0 <= N <= 10^6
Where N is the length of the input string.

Time Limit: 1 second

Sample Input 1 :
abcdcba
Sample Output 1 :
true

Sample Input 2:
coding
Sample Output 2:
false

*/

#include<bits/stdc++.h>
using namespace std;

bool isPalin(string & s) {
	for (int i = 0, j = s.size() - 1; i < j; i++, j--) {
		if (s[i] != s[j])
			return false;
	}
	return true;
}

int main() {

	string s;

	getline(cin, s);

	cout << (isPalin(s) ? "true" : "false") << endl;

	return 0;

}