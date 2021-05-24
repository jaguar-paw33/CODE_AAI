#include<bits/stdc++.h>
using namespace std;

template<typename T>
class binaryTreeNode {
public:
	T data;
	binaryTreeNode<T> * left;
	binaryTreeNode<T> * right;

	binaryTreeNode(T data) {
		this->data = data;
		this->left = NULL;
		this->right = NULL;
	}

	~binaryTreeNode() {
		delete left;
		delete right;
	}
};