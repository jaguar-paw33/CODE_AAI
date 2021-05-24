/*

Given a string S, you need to remove all the duplicates. That means, the output string should contain each character only once. The respective order of characters should remain same, as in the input string.

Input format:
The first and only line of input contains a string, that denotes the value of S.

Output format :
The first and only line of output contains the updated string, as described in the task.

Constraints :
0 <= Length of S <= 10^8
Time Limit: 1 sec

Sample Input 1 :
ababacd
Sample Output 1 :
abcd

Sample Input 2 :
abcde
Sample Output 2 :
abcde

*/

#include<bits/stdc++.h>
using namespace std;

string unique_chars(string & input) {
	unordered_map<int, bool> m;
	string output = "";
	for (int i = 0; i < input.size(); i++) {
		if (!m[input[i]]) {
			m[input[i]] = true;
			output += input[i];
		}
	}
	return output;
}

int main() {
	string input;
	getline(cin, input);
	cout << unique_chars(input) << endl;
	return 0;
}