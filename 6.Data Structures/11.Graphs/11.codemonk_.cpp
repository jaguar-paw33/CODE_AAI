/*

Given a NxM matrix containing Uppercase English Alphabets only. Your task is to tell if there is a path in the given matrix which makes the sentence “CODEMONK” .

There is a path from any cell to all its neighbouring cells. For a particular cell, neighbouring cells are those cells that share an edge or a corner with the cell.

Input Format :
The first line of input contains two space separated integers N and M, where N is number of rows and M is the number of columns in the matrix.
Each of the following N lines contain M characters. Please note that characters are not space separated.

Output Format :
Print 1 if there is a path which makes the sentence "CODEMONK" else print 0.

Constraints :
1 <= N <= 1000
1 <= M <= 1000
Time Limit: 1 second

Sample Input 1:
2 8
CXDXMXNX
XOXEXOXK
Sample Output 1:
1

*/

#include<bits/stdc++.h>
using namespace std;

bool isValid(int row, int col, int n, int m) {
	if (row < 0 || col < 0 || row >= n || col >= m)
		return false;
	return true;
}

bool hasPath(char ** board, int row, int col, int n, int m, bool ** visited, string s) {
	if (!s.size())
		return true;

	bool ans = false;

	visited[row][col] = true;

	int arr[8][2] = {{ -1, -1}, { -1, 0}, { -1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

	for (int i = 0; i < 8; i++) {
		int r = row + arr[i][0];
		int c = col + arr[i][1];

		if (isValid(r, c, n, m) && board[r][c] == s[0] && !visited[r][c]) {
			ans = hasPath(board, r, c, n, m, visited, s.substr(1));
		}
		if (ans)
			return ans;
	}

	visited[row][col] = false;

	return false;
}


int main() {

	int n, m;
	cin >> n >> m;

	char ** board = new char * [n];

	for (int i = 0; i < n; i++) {
		board[i] = new char [m];
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}

	bool ** visited = new bool * [n];
	for (int i = 0; i < n; i++) {
		visited[i] = new bool [m];
		for (int j = 0; j < m; j++) {
			visited[i][j] = false;
		}
	}

	bool ans = false;

	string s = "CODEMONK";

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 'C')
				ans = hasPath(board, i, j, n, m, visited, s.substr(1));
			if (ans)
				break;
		}
		if (ans)
			break;
	}

	cout << ans << endl;

	for (int i = 0; i < n; i++) {
		delete [] board[i];
		delete [] visited[i];
	}

	delete [] board;
	delete [] visited;

	return 0;
}