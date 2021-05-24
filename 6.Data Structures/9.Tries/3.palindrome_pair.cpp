/*

Given 'n' number of words, you need to find if there exist any two words which can be joined to make a palindrome or any word, which itself is a palindrome.
The function should return either true or false. You don't have to print anything.

Input Format :
The first line of the test case contains an integer value denoting 'n'.

The following contains 'n' number of words each separated by a single space.

Output Format :
The first and only line of output contains true if the conditions described in the task are met and false otherwise.

Constraints:
0 <= n <= 10^5
Time Limit: 1 sec

Sample Input 1 :
4
abc def ghi cba
Sample Output 1 :
true
Explanation of Sample Input 1:
"abc" and "cba" forms a palindrome

Sample Input 2 :
2
abc def
Sample Output 2 :
false
Explanation of Sample Input 2:
Neither their exists a pair which forms a palindrome, nor any of the words is a palindrome in itself. Hence, the output is 'false.'

*/

#include<bits/stdc++.h>
#include"trie.h"
using namespace std;

int main() {
	Trie t;
	int n;
	cin >> n;
	vector<string> words;
	while (n--) {
		string word;
		cin >> word;
		words.push_back(word);
	}
	cout << t.palindrome_pair(words) << endl;
	return 0;
}