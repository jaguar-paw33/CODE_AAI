/*

Given an integer n, using phone keypad find out all the possible strings that can be made using digits of input n.

Return empty string for numbers 0 and 1.

Note : 1. The order of strings are not important.
2. Input and output has already been managed for you. You just have to populate the output array and return the count of elements populated in the output array.

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

int return_keypad(int num, string * output) {
	if (num <= 0)
		return 1;

	int size = return_keypad(num / 10, output);

	string s = code(num % 10);

	if (num % 10 == 7 || num % 10 == 9) {
		for (int i = 0; i < size; i++) {
			output[i + size] = output[i] + s[1];
			output[i + 2 * size] = output[i] + s[2];
			output[i + 3 * size] = output[i] + s[3];
			output[i] = output[i] + s[0];
		}
		return 4 * size;
	} else {
		for (int i = 0; i < size; i++) {
			output[i + size] = output[i] + s[1];
			output[i + 2 * size] = output[i] + s[2];
			output[i] = output[i] + s[0];
		}
		return 3 * size;
	}
}

int main() {
	int num;
	cin >> num;

	string output[100000];

	int size = return_keypad(num, output);

	for (int i = 0; i < size; i++) {
		cout << output[i] << endl;
	}

	return 0;
}