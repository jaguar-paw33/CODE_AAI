/*

Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).

Example 1:

Input: root = [3,9,20,null,null,15,7]
Output: [[3],[20,9],[15,7]]
Example 2:

Input: root = [1]
Output: [[1]]
Example 3:

Input: root = []
Output: []


Constraints:

The number of nodes in the tree is in the range [0, 2000].
-100 <= Node.val <= 100

Problem Practice Link: https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

C Program: https://ideone.com/I0MooX

Python Program Recursive: https://onlinegdb.com/rkv9aXUar

Iterative solution: https://ideone.com/l6Voup

Python Solution: https://onlinegdb.com/B1EuvVUaB

Similar Questions:

BInary Tree Level Order traversal: https://leetcode.com/problems/binary-tree-level-order-traversal/

*/

#include<bits/stdc++.h>
#include"level_wise_input_output.h"
using namespace std;

vector<vector<int>> zigzagLevelOrder(binaryTreeNode* root) {

	vector<vector<int>> ans;

	if (!root)
		return ans;

	stack<binaryTreeNode *> lr;
	stack<binaryTreeNode *> rl;

	lr.push(root);

	vector<int> * level = new vector<int>;

	while (!lr.empty() || !rl.empty()) {

		while (!lr.empty()) {
			binaryTreeNode * temp = lr.top();
			lr.pop();

			level->push_back(temp->data);

			if (temp->left) {
				rl.push(temp->left);
			}

			if (temp->right) {
				rl.push(temp->right);
			}

			if (lr.empty()) {
				ans.push_back(*level);

				if (rl.empty()) {
					return ans;
				}

				level = new vector<int>;
			}
		}

		while (!rl.empty()) {
			binaryTreeNode * temp = rl.top();
			rl.pop();

			level->push_back(temp->data);

			if (temp->right) {
				lr.push(temp->right);
			}

			if (temp->left) {
				lr.push(temp->left);
			}

			if (rl.empty()) {
				ans.push_back(*level);

				if (lr.empty()) {
					return ans;
				}

				level = new vector<int>;
			}
		}
	}
	return ans;
}

int main() {
	binaryTreeNode * root = takeInput();

	vector<vector<int>> ans = zigzagLevelOrder(root);

	for (int i = 0; i < ans.size(); i++) {
		for (auto v : ans[i]) {
			cout << v << " ";
		}
		cout << endl;
	}

	delete root;

	return 0;
}