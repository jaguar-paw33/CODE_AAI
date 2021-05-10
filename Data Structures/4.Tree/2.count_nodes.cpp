#include<bits/stdc++.h>
#include"level_wise_input_output.h"
using namespace std;


int nodes_count(treeNode<int> * root) {
	if (!root)
		return 0;
	int ans = 1;
	for (int i = 0; i < root->children.size(); i++) {
		ans += nodes_count(root->children[i]);
	}
	return ans;
}


int main() {
	treeNode<int> * root = takeInput();
	cout << "Number of Nodes : " << nodes_count(root);
	return 0;
}