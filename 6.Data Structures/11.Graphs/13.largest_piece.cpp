/*

It's Gary's birthday today and he has ordered his favourite square cake consisting of '0's and '1's . But Gary wants the biggest piece of '1's and no '0's . A piece of cake is defined as a part which consist of only '1's, and all '1's share an edge with each other on the cake. Given the size of cake N and the cake, can you find the count of '1's in the biggest piece of '1's for Gary ?

Input Format :
The first line of input contains an integer, that denotes the value of N.
Each of the following N lines contain N space separated integers.

Output Format :
Print the count of '1's in the biggest piece of '1's, according to the description in the task.

Constraints :
1 <= N <= 1000
Time Limit: 1 sec

Sample Input 1:
2
1 1
0 1
Sample Output 1:
3

*/

// Sharing an edge means we can move only vertically or horizontally and not diagonally i.e. 4 directions.
// Sharing a corner or an edge means we can move horizontally and vertically and diagonally i.e. 8 directions.


/*

|1*|1*|0|1|
|0|1*|1*|0|
|1*|1*|0|0|

In this example the largest piece is is shown with stars. One thing to note here is that in a piece
we are considering the one which is not a part of sequence starting from (0,0) and ending at (2,0).

!!! KEEP THIS IN MIND WHILE CODING !!!

*/

#include<bits/stdc++.h>
using namespace std;

bool isValid(int row, int col, int n) {
	return (row >= 0 && row < n && col >= 0 && col < n);
}

int max_cake_size(int ** cake, int n, int row, int col, bool ** visited) {
	visited[row][col] = true;
	int s = 0;
	int ways[4][2] = {{ -1, 0}, {0, -1}, {1, 0}, {0, 1}};
	for (int i = 0; i < 4; i++) {
		int r = row + ways[i][0];
		int c = col + ways[i][1];
		if (isValid(r, c, n) && !visited[r][c] && cake[r][c]) {
			s += max_cake_size(cake, n, r, c, visited) + 1;
		}
	}
	return s;
}

int main() {
	int n;
	cin >> n;

	int ** cake = new int * [n];
	for (int i = 0; i < n; i++) {
		cake[i] = new int [n];
		for (int j = 0; j < n; j++) {
			cin >> cake[i][j];
		}
	}

	bool ** visited = new bool * [n];
	for (int i = 0; i < n; i++) {
		visited[i] = new bool [n];
		for (int j = 0; j < n; j++) {
			visited[i][j] = false;
		}
	}

	int max_size = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (cake[i][j] && !visited[i][j]) {

				int size = max_cake_size(cake, n, i, j, visited) + 1;
				if (max_size < size) {
					max_size = size;
				}
			}
		}
	}
	cout << max_size << endl;
	for (int i = 0; i < n; i++) {
		delete [] visited[i];
		delete [] cake[i];
	}
	delete [] visited;
	delete [] cake;

	return 0;
}


