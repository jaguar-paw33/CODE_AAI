/*

Given a generic tree and an integer n. Find and return the node with next larger element in the tree i.e. find a node with value just greater than n.

Note: Return NULL if no node is present with the value greater than n.

Input format :
The first line of input contains data of the nodes of the tree in level order form. The order is: data for root node, number of children to root node, data of each of child nodes and so on and so forth for each node. The data of the nodes of the tree is separated by space.
The following line contains an integer, that denotes the value of n.

Output format :
The first and only line of output contains data of the node, whose data is just greater than n.

Constraints:
Time Limit: 1 sec

Sample Input 1 :
10 3 20 30 40 2 40 50 0 0 0 0
18
Sample Output 1 :
20

Sample Input 2 :
10 3 20 30 40 2 40 50 0 0 0 0
21
Sample Output 2:
30

*/

#include<bits/stdc++.h>
#include"level_wise_input_output.h"
using namespace std;

treeNode<int> * next_larger(treeNode<int> * root, int x) {
	if (!root)
		return root;
	treeNode<int> * ans = NULL;
	if (root->data > x)
		ans = root;
	for (int i = 0; i < root->children.size(); i++) {
		treeNode<int> * temp = next_larger(root->children[i], x);
		if (ans && temp && (ans->data > temp->data))
			ans = temp;
		else if (!ans && temp)
			ans = temp;
	}
	return ans;
}

int main() {
	treeNode<int> * root = takeInput();
	int x;
	cin >> x;
	treeNode<int> * ans = next_larger(root, x);
	if (!ans)
		cout << "No Node is Present" << endl;
	else
		cout << ans->data << endl;
	return 0;
}