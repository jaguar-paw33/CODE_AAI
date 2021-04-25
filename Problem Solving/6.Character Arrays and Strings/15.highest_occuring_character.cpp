/*

For a given a string(str), find and return the highest occurring character.

Example:

Input String: "abcdeapapqarr"

Expected Output: 'a'
Since 'a' has appeared four times in the string which happens to be the highest frequency character, the answer would be 'a'.
If there are two characters in the input string with the same frequency, return the character which comes first.

Consider:
Assume all the characters in the given string to be in lowercase always.

Input Format:
The first and only line of input contains a string without any leading and trailing spaces.

Output Format:
The only line of output prints the updated string.

Note:
You are not required to print anything explicitly. It has already been taken care of.

Constraints:
0 <= N <= 10^6
Where N is the length of the input string.

Time Limit: 1 second

Sample Input 1:
abdefgbabfba
Sample Output 1:
b

Sample Input 2:
xy
Sample Output 2:
x

*/

#include<bits/stdc++.h>
using namespace std;

char highest_occuring_char(string & s) {

	int char_count[26];

	memset(char_count, 0, 26 * sizeof(int));

	for (int i = 0; i < s.size(); i++) {
		char_count[s[i] - 'a']++;
	}
	char ans;
	int count = INT_MIN;
	for (int i = 0; i < s.size(); i++) {
		if (count < char_count[s[i] - 'a'])
		{
			ans = s[i];
			count = char_count[s[i] - 'a'];
		}
	}

	return ans;
}

int main() {
	string s;
	getline(cin, s);

	cout << highest_occuring_char(s) << endl;

	return 0;
}