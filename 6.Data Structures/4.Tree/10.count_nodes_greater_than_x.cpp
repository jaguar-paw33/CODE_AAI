/*

Given a tree and an integer x, find and return the number of nodes which contains data greater than x.

Input format:
The first line of input contains data of the nodes of the tree in level order form. The order is: data for root node, number of children to root node, data of each of child nodes and so on and so forth for each node. The data of the nodes of the tree is separated by space.

The following line contains an integer, that denotes the value of x.

Output Format :
The first and only line of output prints the count of nodes greater than x.

Constraints:
Time Limit: 1 sec

Sample Input 1 :
10 3 20 30 40 2 40 50 0 0 0 0
35
Sample Output 1 :
3

Sample Input 2 :
10 3 20 30 40 2 40 50 0 0 0 0
10
Sample Output 2:
5

*/

#include<bits/stdc++.h>
#include"level_wise_input_output.h"
using namespace std;

int greater_than_x(treeNode<int> * root, int x) {
	if (!root)
		return 0;
	int ans = 0;
	if (root->data > x)
		ans += 1;
	for (int i = 0; i < root->children.size(); i++) {
		ans += greater_than_x(root->children[i], x);
	}
	return ans;
}

int main() {
	treeNode<int> * root = takeInput();
	int x;
	cin >> x;
	cout << "Number of Nodes greater than " << x << " are " << greater_than_x(root, x) << endl;
	return 0;
}