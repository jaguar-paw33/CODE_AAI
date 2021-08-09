/*

According to the Wikipedia's article: "The Game of Life, also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970."

Given a board with m by n cells, each cell has an initial state live (1) or dead (0). Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):

Any live cell with fewer than two live neighbors dies, as if caused by under-population.

Any live cell with two or three live neighbors lives on to the next generation.

Any live cell with more than three live neighbors dies, as if by over-population..

Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.

Write a function to compute the next state (after one update) of the board given its current state. The next state is created by applying the above rules simultaneously to every cell in the current state, where births and deaths occur simultaneously.

Example:

Input:

[

  [0,1,0],

  [0,0,1],

  [1,1,1],

  [0,0,0]

]

Output:

[

  [0,0,0],

  [1,0,1],

  [0,1,1],

  [0,1,0]

]

Level: Medium

Problem Practice link: https://leetcode.com/problems/game-of-life/

Similar Questions:

Set Matrix Zeros: https://leetcode.com/problems/set-matrix-zeroes/

*/

#include<bits/stdc++.h>
using namespace std;

int isValid(int rows, int cols, int i, int j) {
	return (i >= 0 && i < rows && j >= 0 && j < cols);
}

int numLiveNeighbors(vector<vector<int>> & board, int row, int col) {
	int arr[8][2] = {
		{ -1, -1}, { -1, 0}, { -1, 1},
		{ 0, -1}, {0, 1},
		{ 1, -1}, { 1, 0}, {1, 1},
	};
	int num = 0;
	for (int i = 0; i < 8; i++) {
		int r = row + arr[i][0];
		int c = col + arr[i][1];
		if (isValid(board.size(), board[0].size(), r, c) && (board[r][c] == 1 || board[r][c] == -2)) {
			num++;
		}
	}
	return num;
}

void gameOfLife(vector<vector<int>>& board) {

	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board[i].size(); j++) {

			int numLive = numLiveNeighbors(board, i, j);

			if (board[i][j]) {
				if (numLive < 2 || numLive > 3)
					board[i][j] = -2;
			} else if (numLive == 3)
				board[i][j] = -1;
		}
	}

	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board[i].size(); j++) {
			if (board[i][j] == -1) {
				board[i][j] = 1;
			} else if (board[i][j] == -2) {
				board[i][j] = 0;
			}
		}
	}
}


int main() {
	int m, n;

	cin >> m >> n;

	int rows = m, cols = n;

	int v;

	vector<vector<int>> board;

	while (rows--) {
		cols = n;
		vector<int> row;
		while (cols--) {
			cin >> v;
			row.push_back(v);
		}
		board.push_back(row);
	}

	gameOfLife(board);

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
}