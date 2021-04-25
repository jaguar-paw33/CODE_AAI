/*

Take input a stream of n integer elements, find the second largest element present.
The given elements can contain duplicate elements as well. If only 0 or 1 element is given, the second largest should be INT_MIN ( - 2^31 ).
Input format :

Line 1 : Total number of elements (n)

Line 2 : N elements (separated by space)

Sample Input 1:
 4
 3 9 0 9
Sample Output 1:
 3
Sample Input 2 :
 2
 4 4
Sample Output 2:
 -2147483648
Sample Output Explanation:
Since both the elements are equal here, hence second largest element is INT_MIN i.e. ( -2^31 )

*/

#include<iostream>
#include<climits>
using namespace std;


int main() {
	int n;
	cin >> n;

	int first, second = INT_MIN;


	if (n == 0 || n == 1)
	{
		cout << INT_MIN << endl;
		return 0;
	}

	cin >> first;

	n -= 1;

	while (n--) {
		int v;
		cin >> v;

		if (v > first)
		{
			second = first;
			first = v;

		} else if (v > second && v < first) {
			second = v;
		}
	}

	cout << second << endl;

	return 0;
}