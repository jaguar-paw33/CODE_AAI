/*

	There are three types of notations to represent a arthimetic operation.

	1. Infix - A+B (The operator is in between the operands)
	2. Prefix - +AB (The operator is before the operands)
	3. Postfix - AB+ (The operator is after the operands).

In general when we do not use paranthesis, expression written in Postfix or Prefix Notations are non-ambiguous while the
expression written in Inifix Notation are ambiguos. For example,

Suppose we have this expression A+B*C in Infix Notation,

Now, since we are not explicityl using paranthesis and hence this expression can be interpreted
either as ((A+B)*C) or (A+(B*C)). Hence, there is an ambigutiy while using Infix Notation.

Now, the prefix form of the expression can be written in two ways,

1. *+ABC - This expression clearly denotes that first we need to add A and B and the multiply the result with C.
2. +A*BC - This expressinf clearly denotes that first B anc C should be multiplied and then the result should be added with A.

Now, the postfix form of the expression can be written in two ways,

1. ABC*+ - This expression  clearly denotes that first B and C will be multiplied and then the result will be added to A.
2. AB+C* - This expression clearly denotes that first we need to add A and B and then the result will be multiplied with C.

*/

#include<bits/stdc++.h>
using namespace std;

int priority(char c) {
	if (c == '(')
		return 0;
	else if (c == '+' || c == '-')
		return 1;
	else if (c == '*' || c == '/')
		return 2;
	else if (c == '^')
		return 3;
	else {
		cout << "Invalid Character" << endl;
		return -1;
	}
}

string infix_to_postfix(string & exp) {
	stack<char> s;

	string postfix = "";

	for (int i = 0; i < exp.size(); i++) {
		if (isalnum(exp[i])) {
			postfix += exp[i];
		} else if (exp[i] == '(')
			s.push(exp[i]);
		else if (exp[i] == ')') {
			while (s.top() != '(')
			{
				postfix += s.top();
				s.pop();
			}
			s.pop();
		} else {
			while (!s.empty() && priority(s.top()) > priority(exp[i])) {
				postfix += s.top();
				s.pop();
			}
			s.push(exp[i]);
		}
	}

	while (!s.empty())
	{
		postfix += s.top();
		s.pop();
	}

	return postfix;
}

int operate(int a, int b, char op) {
	if (op == '+')
		return a + b;
	else if (op == '-')
		return a - b;
	else if (op == '*')
		return a * b;
	else if (op == '/')
		return a / b;
	else if (op == '^')
		return int(pow(a, b));
	else {
		cout << "Invalid Operand" << endl;
		return -1;
	}
}

int evaluate_postfix(string & postix) {
	stack<char> s;
	for (int i = 0; i < postix.size(); i++) {
		if (isalnum(postix[i])) {
			s.push(postix[i]);
		} else {

			int a = s.top() - 48;
			s.pop();
			int b = s.top() - 48;
			s.pop();

			s.push(operate(a, b, postix[i]) + 48);
		}
	}
	return s.top() - 48;
}





void rev(string & exp) {
	for (int i = 0, j = exp.size() - 1; i <= j; i++, j--) {
		char temp = exp[i];
		exp[i] = exp[j];
		exp[j] = temp;
	}

	for (int i = 0; i < exp.size(); i++) {
		if (exp[i] == ')')
			exp[i] = '(';
		else if (exp[i] == '(')
			exp[i] = ')';
	}
}

string infix_to_prefix(string exp) {

	rev(exp); // Reverse the expression keeping the bracekts valid
	string prefix = infix_to_postfix(exp); // compute postfix
	rev(prefix); // reversed postfix is the prefix
	return prefix;
}

int evaluate_prefix(string prefix) {
	rev(prefix);
	return evaluate_postfix(prefix);
}

int main() {
	string exp;
	cin >> exp;

	cout << "Infix : " << exp << endl;
	string postfix = infix_to_postfix(exp);
	cout << "Postfix : " << postfix << endl;
	string prefix = infix_to_prefix(exp);
	cout << "Prefix : " << prefix << endl;

	cout << "Postfix Evaluation : " << evaluate_postfix(postfix) << endl;
	cout << "Prefix Evaluation : " << evaluate_prefix(prefix) << endl;

	return 0;
}