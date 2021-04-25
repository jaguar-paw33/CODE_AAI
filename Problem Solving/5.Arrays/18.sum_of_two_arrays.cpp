/*

Two random integer arrays/lists have been given as ARR1 and ARR2 of size N and M respectively. Both the arrays/lists contain numbers from 0 to 9(i.e. single digit integer is present at every index). The idea here is to represent each array/list as an integer in itself of digits N and M.
You need to find the sum of both the input arrays/list treating them as two integers and put the result in another array/list i.e. output array/list will also contain only single digit at every index.
Note:
The sizes N and M can be different.

Output array/list(of all 0s) has been provided as a function argument. Its size will always be one more than the size of the bigger array/list. Place 0 at the 0th index if there is no carry.

No need to print the elements of the output array/list.
Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

First line of each test case or query contains an integer 'N' representing the size of the first array/list.

Second line contains 'N' single space separated integers representing the elements of the first array/list.

Third line contains an integer 'M' representing the size of the second array/list.

Fourth line contains 'M' single space separated integers representing the elements of the second array/list.
Output Format :
For each test case, print the required sum of the arrays/list in a row, separated by a single space.

Output for every test case will be printed in a separate line.
Constraints :
1 <= t <= 10^2
0 <= N <= 10^5
0 <= M <= 10^5
Time Limit: 1 sec
Sample Input 1:
1
3
6 2 4
3
7 5 6
Sample Output 1:
1 3 8 0
Sample Input 2:
2
3
8 5 2
2
1 3
4
9 7 6 1
3
4 5 9
Sample Output 2:
0 8 6 5
1 0 2 2 0

*/

#include<bits/stdc++.h>
using namespace std;

void sum_array(int * arr1, int n1, int * arr2, int n2) {
	int * sum = new int [max(n1, n2) + 1];

	memset(sum, 0, (max(n1, n2) + 1)*sizeof(int));

	int i, j, k;

	for (i = n1 - 1, j = n2 - 1, k = max(n1, n2); i >= 0 && j >= 0; i--, j--) {
		int s = sum[k] + arr1[i] + arr2[j];
		sum[k--] = s % 10;
		sum[k] = s / 10;
	}

	while (i >= 0) {
		int s = sum[k] + arr1[i--];
		sum[k--] = s % 10;
		sum[k] = s / 10;
	}

	while (j >= 0) {
		int s = sum[k] + arr2[j--];
		sum[k--] = s % 10;
		sum[k] = s / 10;
	}

	for (int i = 0; i < max(n1, n2) + 1; i++) {
		cout << sum[i] << " ";
	}

	delete [] sum;
}

int main() {
	int n1, n2;
	cin >> n1 >> n2;

	int * arr1 = new int [n1];

	for (int i = 0; i < n1; i++) {
		cin >> arr1[i];
	}

	int * arr2 = new int [n2];

	for (int i = 0; i < n2; i++) {
		cin >> arr2[i];
	}

	sum_array(arr1, n1, arr2, n2);

	delete [] arr1;
	delete [] arr2;

	return 0;
}