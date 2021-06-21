/*

Gary has a board of size NxM. Each cell in the board is a coloured dot. There exist only 26 colours denoted by uppercase Latin characters (i.e. A,B,...,Z). Now Gary is getting bored and wants to play a game. The key of this game is to find a cycle that contain dots of same colour. Formally, we call a sequence of dots d1, d2, ..., dk a cycle if and only if it meets the following condition:

1. These k dots are different: if i ≠ j then di is different from dj.
2. k is at least 4.
3. All dots belong to the same colour.
4. For all 1 ≤ i ≤ k - 1: di and di + 1 are adjacent. Also, dk and d1 should also be adjacent. Cells x and y are called adjacent if they share an edge.

Since Gary is colour blind, he wants your help. Your task is to determine if there exists a cycle on the board.

Input Format :
The first line of input contains two space separated integers N and M, where N is number of rows and M is the number of columns of the board.
Each of the following N lines contain M characters. Please note that characters are not space separated. Each character is an uppercase Latin letter.

Output Format :
Print true if there is a cycle in the board, else print false.

Constraints :
2 <= N <= 1000
2 <= M <= 1000
Time Limit: 1 second

Sample Input 1:
3 4
AAAA
ABCA
AAAA
Sample Output 1:
true

*/

#include<bits/stdc++.h>
using namespace std;

bool isValid(int row, int col, int n, int m) {
	return (row >= 0 && row < n && col >= 0 && col < m);
}

bool hasCycle(char ** board, int n, int m, int row, int col, int count, bool ** visited) {

	visited[row][col] = true;

	int ways[4][2] = {{ -1, 0}, {0, -1}, {1, 0}, {0, 1}};
	for (int i = 0; i < 4; i++) {
		int r = row + ways[i][0];
		int c = col + ways[i][1];
		if (isValid(r, c, n, m) && (board[row][col] == board[r][c]))
		{
			if (!visited[r][c])
				if (hasCycle(board, n, m, r, c, count + 1, visited))
					return true;
				else if (count >= 4)
					return true;
		}
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
		visited[i] = new bool[m];
		for (int j = 0; j < m; j++) {
			visited[i][j] = false;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (hasCycle(board, n, m, i, j, 0, visited))
			{
				cout << "true" << endl;
				for (int i = 0; i < n; i++) {
					delete [] board[i];
					delete [] visited[i];
				}
				delete [] visited;
				delete [] board;
				return 0;
			}
		}
	}

	cout << "false" << endl;

	for (int i = 0; i < n; i++) {
		delete board[i];
		delete [] visited[i];
	}
	delete [] visited;
	delete [] board;
	return 0;
}
