/*

Given an array of integers, determine whether the array can be sorted in ascending order using only one of the following operations one time.

Swap two elements.
Reverse one sub-segment.
Determine whether one, both or neither of the operations will complete the task. Output is as follows.

If the array is already sorted, output yes on the first line. You do not need to output anything else.

If you can sort this array using one single operation (from the two permitted operations) then output yes on the first line and then:

If elements can only be swapped,  and , output swap l r in the second line.  and  are the indices of the elements to be swapped, assuming that the array is indexed from  to .
If elements can only be reversed, for the segment , output reverse l r in the second line.  and  are the indices of the first and last elements of the subarray to be reversed, assuming that the array is indexed from  to . Here  represents the subarray that begins at index  and ends at index , both inclusive.
If an array can be sorted both ways, by using either swap or reverse, choose swap.

If the array cannot be sorted either way, output no on the first line.
Example

Either swap the  and  at indices 3 and 4, or reverse them to sort the array. As mentioned above, swap is preferred over reverse. Choose swap. On the first line, print yes. On the second line, print swap 3 4.

Function Description

Complete the almostSorted function in the editor below.

almostSorted has the following parameter(s):

int arr[n]: an array of integers
Prints

Print the results as described and return nothing.
Input Format

The first line contains a single integer , the size of .
The next line contains  space-separated integers  where .

Constraints



All  are distinct.

Output Format

If the array is already sorted, output yes on the first line. You do not need to output anything else.

If you can sort this array using one single operation (from the two permitted operations) then output yes on the first line and then:

a. If elements can be swapped,  and , output swap l r in the second line.  and  are the indices of the elements to be swapped, assuming that the array is indexed from  to .

b. Otherwise, when reversing the segment , output reverse l r in the second line.  and  are the indices of the first and last elements of the subsequence to be reversed, assuming that the array is indexed from  to .

 represents the sub-sequence of the array, beginning at index  and ending at index , both inclusive.

If an array can be sorted by either swapping or reversing, choose swap.

If you cannot sort the array either way, output no on the first line.
Sample Input 1

STDIN   Function
-----   --------
2       arr[] size n = 2
4 2     arr = [4, 2]
Sample Output 1

yes
swap 1 2
Explanation 1

You can either swap(1, 2) or reverse(1, 2). You prefer swap.

Sample Input 2

3
3 1 2
Sample Output 2

no
Explanation 2

It is impossible to sort by one single operation.

Sample Input 3

6
1 5 4 3 2 6
Sample Output 3

yes
reverse 2 5
Explanation 3

You can reverse the sub-array d[2...5] = "5 4 3 2", then the array becomes sorted.

Practise Problem Link - https://www.hackerrank.com/challenges/almost-sorted/problem

*/


#include<bits/stdc++.h>
using namespace std;

void almostSorted(vector<int> arr) {
	vector<int> temp(arr.begin(), arr.end());
	sort(temp.begin(), temp.end());

	int si = -1, ei = -1;

	for (int i = 0; i < arr.size(); i++) {
		if (arr[i] != temp[i]) {
			si = i;
			break;
		}
	}

	for (int j = arr.size() - 1; j >= 0; j--) {
		if (arr[j] != temp[j]) {
			ei = j;
			break;
		}
	}

	if (si == -1) {
		cout << "no" << endl;
		return;
	}

	bool reverseSorted = false, ascSorted = false;

	for (int i = si + 1; i <= ei; i++) {
		if (arr[i] > arr[i - 1]) {
			reverseSorted = false;
			break;
		} else {
			reverseSorted = true;
		}
	}

	if (reverseSorted) {
		cout << "yes" << endl;
		if (ei - si + 1 == 2) {
			cout << "swap " << si + 1 << " " << ei + 1 << endl;
		} else {
			cout << "reverse " << si + 1 << " " << ei + 1 << endl;
		}
		return;
	}

	for (int i = si + 2; i < ei - 1; i++) {
		if (arr[i] < arr[i - 1]) {
			ascSorted = false;
			break;
		} else {
			ascSorted = true;
		}
	}

	if (ascSorted) {
		cout << "yes" << endl;
		cout << "swap " << si + 1 << " " << ei + 1 << endl;
		return;
	}

	cout << "no" << endl;

}

int main() {
	int n;
	cin >> n;

	vector<int> arr;
	int v;

	while (n--) {
		cin >> v;
		arr.push_back(v);
	}

	almostSorted(arr);

	return 0;
}
