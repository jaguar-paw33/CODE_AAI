/*

Suppose you have a string, S, made up of only 'a's and 'b's. Write a recursive function that checks if the string was generated using the following rules:

a. The string begins with an 'a'
b. Each 'a' is followed by nothing or an 'a' or "bb"
c. Each "bb" is followed by nothing or an 'a'

If all the rules are followed by the given string, return true otherwise return false.

Input format :
String S

Output format :
'true' or 'false'

Constraints :
0 <= |S| <= 1000
where |S| represents length of string S.

Sample Input 1 :
abb
Sample Output 1 :
true

Sample Input 2 :
abababa
Sample Output 2 :
false

*/

#include<bits/stdc++.h>
using namespace std;

bool check_ab(char * input) {
	if (strlen(input) == 1 && input[0] == 'a')
		return true;
	else if (strlen(input) == 2 && input[0] == 'a' && input[1] == 'a')
		return true;
	else if (strlen(input) == 3 && input[0] == 'a' && input[1] == 'b' && input[2] == 'b')
		return true;
	else if (strlen(input) == 4 && input[0] == 'a' && input[1] == 'b' && input[2] == 'b' && input[3] == 'a')
		return true;
	else if (strlen(input) > 1 && input[1] == 'a')
		return check_ab(input + 1);
	else if (strlen(input) > 2 && input[1] == 'b' && input[2] == 'b')
		return check_ab(input + 2);
	else return false;
}

int main() {
	char input[1000];
	cin >> input;

	cout << (check_ab(input) ? "true" : "false") << endl;

	return 0;
}