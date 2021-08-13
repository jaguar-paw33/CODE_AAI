/*

Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).


Example 1:

Input: root = [3,9,20,null,null,15,7]
Output: [[3],[9,20],[15,7]]
Example 2:

Input: root = [1]
Output: [[1]]
Example 3:

Input: root = []
Output: []


Constraints:

The number of nodes in the tree is in the range [0, 2000].
-1000 <= Node.val <= 1000

Level: Medium


Problem Practice Link: https://leetcode.com/problems/binary-tree-level-order-traversal/

C Program: https://ideone.com/1AQBPx

Python Code: https://onlinegdb.com/SJu_xzS6H

Similar Questions:

Binary Tree level order traversal II : https://leetcode.com/problems/binary-tree-level-order-traversal-ii/

Minimum Depth of Binary treee: https://leetcode.com/problems/minimum-depth-of-binary-tree/

Average of levels in binary tree: https://leetcode.com/problems/average-of-levels-in-binary-tree/

Cousins in a binary tree: https://leetcode.com/problems/cousins-in-binary-tree/

*/

#include<bits/stdc++.h>
#include"level_wise_input_output.h"
using namespace std;

vector<vector<int>> levelOrder(binaryTreeNode* root) {

	vector<vector<int>> ans;


	if (!root)
		return ans;

	queue<binaryTreeNode * > pending;
	pending.push(root);
	pending.push(NULL);

	vector<int> * level = new vector<int>;

	while (!pending.empty()) {

		binaryTreeNode * temp = pending.front();
		pending.pop();

		if (!temp) {
			ans.push_back(*level);
			level = new vector<int>;

			if (pending.empty()) {
				return ans;
			}

			pending.push(NULL);
			continue;
		}

		level->push_back(temp->data);

		if (temp->left) {
			pending.push(temp->left);
		}

		if (temp->right) {
			pending.push(temp->right);
		}

	}

	return ans;
}

int main() {
	binaryTreeNode * root = takeInput();

	vector<vector<int>> ans = levelOrder(root);

	for (int i = 0; i < ans.size(); i++) {
		for (auto v : ans[i]) {
			cout << v << " ";
		}
		cout << endl;
	}

	delete root;

	return 0;
}