/*

Given a string S, compute recursively a new string where identical chars that are adjacent in the original string are separated from each other by a "*".

Input format :
String S

Output format :
Modified string

Constraints :
0 <= |S| <= 1000
where |S| represents length of string S.

Sample Input 1 :
hello
Sample Output 1:
hel*lo

Sample Input 2 :
aaaa
Sample Output 2 :
a*a*a*a

*/

#include<bits/stdc++.h>
using namespace std;

void pair_star(char * input) {
	if (strlen(input) <= 0)
		return;

	if (input[0] == input[1]) {
		for (int i = strlen(input); i >= 1; i--) {
			input[i + 1] = input[i];
		}
		input[1] = '*';
	}
	pair_star(input + 1);
}

int main() {
	char input[1000];
	cin >> input;

	pair_star(input);

	cout << input << endl;

	return 0;
}