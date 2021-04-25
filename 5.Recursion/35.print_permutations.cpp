/*

Given an input string (STR), find and return all possible permutations of the input string.

Note:
The input string may contain the same characters, so there will also be the same permutations.
The order of permutations doesn’t matter.

Input Format:
The only input line contains a string (STR) of alphabets in lower case

Output Format:
Print each permutations in a new line

Note:
You do not need to print anything, it has already been taken care of. Just implement the function.

Constraint:
1<=length of STR<=8
Time Limit: 1sec

Sample Input 1:
cba
Sample Output 1:
abc
acb
bac
bca
cab
cba

*/

#include<bits/stdc++.h>
using namespace std;

void print_permutations(string s, string output) {
	if (!s.size()) {
		cout << output << endl;
		return;
	}

	for (int i = 0; i < s.size(); i++) {
		print_permutations(s.substr(0, i) + s.substr(i + 1), output + s[i]);
	}
}

int main() {
	string s;
	cin >> s;

	print_permutations(s, "");

	return 0;
}

