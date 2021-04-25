/*

Given k, find the geometric sum i.e.
1 + 1/2 + 1/4 + 1/8 + ... + 1/(2^k)
using recursion.

Input format :
Integer k

Output format :
Geometric sum (upto 5 decimal places)

Constraints :
0 <= k <= 1000

Sample Input 1 :
3
Sample Output 1 :
1.87500

Sample Input 2 :
4
Sample Output 2 :
1.93750

*/


#include<bits/stdc++.h>
using namespace std;

float geometric_sum(int k) {
	if (k < 0)
		return 0;
	return 1 / pow(2, k) + geometric_sum(k - 1);
}

int main() {
	int k;
	cin >> k;

	printf("%.5f\n", geometric_sum(k));

	return 0;
}
