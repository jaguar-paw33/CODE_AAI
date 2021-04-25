/*

Given an integer n, using phone keypad find out and print all the possible strings that can be made using digits of input n.

Note : The order of strings are not important. Just print different strings in new lines.

Input Format :
Integer n

Output Format :
All possible strings in different lines

Constraints :
1 <= n <= 10^6

Sample Input:
23

Sample Output:
ad
ae
af
bd
be
bf
cd
ce
cf

*/



#include<bits/stdc++.h>
using namespace std;

string code(int num) {

	if (num == 2)
		return "abc";
	else if (num == 3)
		return "def";
	else if (num == 4)
		return "ghi";
	else if (num == 5)
		return "jkl";
	else if (num == 6)
		return "mno";
	else if (num == 7)
		return "pqrs";
	else if (num == 8)
		return "tuv";
	else if (num == 9)
		return "wxyz";
	else
		return "";

}

void keypad(int num, string output) {
	if (num <= 0) {
		cout << output << endl;
		return;
	}

	string s = code(num % 10);

	for (int i = 0; i < s.size(); i++) {
		keypad(num / 10, s[i] + output);
	}
}

void print_keypad(int num) {
	keypad(num, "");
}

int main() {
	int num;
	cin >> num;

	print_keypad(num);

	return 0;
}