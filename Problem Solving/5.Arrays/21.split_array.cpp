/*

Given an integer array A of size N, check if the input array can be splitted in two parts such that -

- Sum of both parts is equal
- All elements in the input, which are divisible by 5 should be in same group.
- All elements in the input, which are divisible by 3 (but not divisible by 5) should be in other group.
- Elements which are neither divisible by 5 nor by 3, can be put in any group.

Groups can be made with any set of elements, i.e. elements need not to be continuous. And you need to consider each and every element of input array in some group.

Return true, if array can be split according to the above rules, else return false.

Note : You will get marks only if all the test cases are passed.

Input Format :
Line 1 : Integer N (size of array)
Line 2 : Array A elements (separated by space)

Output Format :
true or false

Constraints :
1 <= N <= 50

Sample Input 1 :
2
1 2
Sample Output 1 :
false

Sample Input 2 :
3
1 4 3
Sample Output 2 :
true

*/

#include<bits/stdc++.h>
using namespace std;

bool split(int * arr, int n, int s1, int s2) {
	if (n == 0)
	{
		if (s1 == s2)
			return true;
		else
			return false;
	}

	if (arr[0] % 5 == 0)
		return split(arr + 1, n - 1, s1 + arr[0], s2);
	else if (arr[0] % 3 == 0)
		return split(arr + 1, n - 1, s1 , s2 + arr[0]);
	else
		return (split(arr + 1, n - 1, s1 + arr[0], s2) || split(arr + 1, n - 1, s1 , s2 + arr[0]));
}

int main() {
	int n;
	cin >> n;

	int * arr = new int [n];

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	cout << (split(arr, n, 0 , 0) ? "true" : "false") << endl;

	delete [] arr;

	return 0;
}