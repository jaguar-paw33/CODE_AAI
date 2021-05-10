#include<bits/stdc++.h>
#include"level_wise_input_output.h"
using namespace std;

pair<int, int> diameter(binaryTreeNode<int> * root) {

	// first - height
	// second - diameter

	if (!root)
	{
		pair<int, int> p(0, 0);
		return p;
	}
	pair<int, int> pl = diameter(root->left);
	pair<int, int> pr = diameter(root->right);
	pair<int, int> ans;
	ans.first = max(pl.first, pr.first) + 1;
	ans.second = max(pl.first + pr.first, max(pl.second, pr.second));
	return ans;
}

int main() {
	binaryTreeNode<int> * root = takeInput();
	printBinaryTree(root);
	cout << diameter(root).first << endl;
	cout << diameter(root).second << endl;
	delete root;
	return 0;
}
