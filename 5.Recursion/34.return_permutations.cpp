/*

Given a string S, find and return all the possible permutations of the input string.

Note 1 : The order of permutations is not important.

Note 2 : If original string contains duplicate characters, permutations will also be duplicates.

Input Format :
String S

Output Format :
All permutations (in different lines)

Sample Input :
abc
Sample Output :
abc
acb
bac
bca
cab
cba

*/

#include<bits/stdc++.h>
using namespace std;

int return_permutations(string s, string output[]) {
	if (!s.size()) {
		output[0] = "";
		return 1;
	}

	string temp[10000];
	int size = 0;

	for (int i = 0; i < s.size(); i++) {
		int temp_size = return_permutations(s.substr(0, i) + s.substr(i + 1), temp);

		for (int j = 0; j < temp_size; j++) {
			output[j + size] = s[i] + temp[j];
		}

		size += temp_size;
	}

	return size;
}

int main() {
	string s;
	cin >> s;

	string output[10000];

	int size = return_permutations(s, output);

	for (int i = 0; i < size; i++) {
		cout << output[i] << endl;
	}

	return 0;
}