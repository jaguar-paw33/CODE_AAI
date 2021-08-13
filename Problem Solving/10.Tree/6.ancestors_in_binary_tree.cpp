/*

Given a Binary Tree and a target key, you need to find all the ancestors of the given target key.

              1
            /   \
          2      3
        /  \
      4     5
     /
    7

Key: 7
Ancestor: 4 2 1
Example 1:

Input:
        1
      /   \
     2     3

target = 2
Output: 1
Example 2:

Input:
         1
       /   \
      2     3
    /  \   /  \
   4    5 6    8
  /
 7

target = 7
Output: 4 2 1
Your Task:
Your task is to complete the function Ancestors() that finds all the ancestors of the key in the given binary tree.

Note:
The return type is
cpp: vector
Java: ArrayList
python: list

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(H).
Note: H is the height of the tree and this space is used implicitly for the recursion stack.

Constraints:
1 ≤ N ≤ 10^3
1 ≤ data of node ≤ 10^4

*/

#include<bits/stdc++.h>
#include"level_wise_input_output.h"
using namespace std;

vector<int> * helper(binaryTreeNode * root, int target) {

	if (!root)
		return NULL;

	if (root->data == target) {
		vector<int> * ans = new vector<int>;
		return ans;
	}

	vector<int> * ans = helper(root->left, target);

	if (ans) {
		ans->push_back(root->data);
		return ans;
	}

	ans = helper(root->right, target);

	if (ans) {
		ans->push_back(root->data);
	}

	return ans;
}

vector<int> Ancestors(binaryTreeNode *root, int target)
{

	vector<int> * ans = helper(root, target);

	if (ans) {
		return *ans;
	} else {
		vector<int> e;
		return e;
	}

}

int main() {
	binaryTreeNode * root = takeInput();

	int target;

	cin >> target;

	vector<int> ans = Ancestors(root, target);

	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}

	delete root;

	return 0;
}