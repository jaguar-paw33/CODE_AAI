/*

Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.


Example 1:

Input: s = "()"
Output: true
Example 2:

Input: s = "()[]{}"
Output: true
Example 3:

Input: s = "(]"
Output: false
Example 4:

Input: s = "([)]"
Output: false
Example 5:

Input: s = "{[]}"
Output: true


Constraints:

1 <= s.length <= 104
s consists of parentheses only '()[]{}'.

Level: Easy

Problem Practice Link: https://leetcode.com/problems/valid-parentheses/

C-code: https://ideone.com/FzlsWG

Python code : https://onlinegdb.com/Hk-WONxhB


*/

#include<bits/stdc++.h>
using namespace std;

bool isValid(string s) {
	stack<char> st;
	for (auto x : s) {
		if (!isalnum(x))
		{
			if (x == '(' || x == '{' || x == '[')
				st.push(x);
			else if (x == ')') {
				if (!st.size() || st.top() != '(')
					return false;
				st.pop();
			} else if (x == '}') {
				if (!st.size() || st.top() != '{')
					return false;
				st.pop();
			} else {
				if (!st.size() || st.top() != '[')
					return false;
				st.pop();
			}
		}
	}
	return st.size() == 0;
}

int main() {
	string s;
	cin >> s;

	cout << isValid(s) << endl;

	return 0;
}