/*

Given a list of n words and a pattern p that we want to search. Check if the pattern p is present the given words or not. Return true if the pattern is present and false otherwise.

Input Format :
The first line of input contains an integer, that denotes the value of n.
The following line contains n space separated words.
The following line contains a string, that denotes the value of the pattern p.

Output Format :
The first and only line of output contains true if the pattern is present and false otherwise.

Constraints:
Time Limit: 1 sec

Sample Input 1 :
4
abc def ghi cba
de
Sample Output 1 :
true

Sample Input 2 :
4
abc def ghi hg
hi
Sample Output 2 :
true

Sample Input 3 :
4
abc def ghi hg
hif
Sample Output 3 :
false

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
		string s;
		cin >> s;
		words.push_back(s);
	}
	string p;
	cin >> p;
	cout << t.find_pattern(words, p) << endl;
	return 0;
}