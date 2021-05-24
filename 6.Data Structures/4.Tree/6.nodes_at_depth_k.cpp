#include<bits/stdc++.h>
#include"level_wise_input_output.h"
using namespace std;

void depth_of_node(treeNode<int> * root, int k) {
	if (!k)
	{
		cout << root->data << endl;
		return;
	}

	for (int i = 0; i < root->children.size(); i++) {
		depth_of_node(root->children[i], k - 1);
	}
}


int main() {
	treeNode<int> * root = takeInput();
	int k;
	cin >> k;
	cout << "Nodes at Depth " << k << endl;
	depth_of_node(root, k);
	return 0;
}