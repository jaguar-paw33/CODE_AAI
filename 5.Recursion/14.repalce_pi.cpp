/*

Given a string, compute recursively a new string where all appearances of "pi" have been replaced by "3.14".

Sample Input 1 :
xpix
Sample Output :
x3.14x

Sample Input 2 :
pipi
Sample Output :
3.143.14

Sample Input 3 :
pip
Sample Output :
3.14p

*/

#include<bits/stdc++.h>
using namespace std;

void replace_pi(char * input) {
	int size = strlen(input);

	if (size <= 0)
		return;

	if (input[0] == 'p' && input[1] == 'i') {
		input[size + 2] = '\0';
		for (int i = size - 1; i >= 0 ; i--) {
			input[i + 2] = input[i];
		}
		input[0] = '3';
		input[1] = '.';
		input[2] = '1';
		input[3] = '4';
	}
	replace_pi(input + 1);
}


int main() {
	char input[100];
	cin >> input;

	replace_pi(input);

	cout << input << endl;

	return 0;
}