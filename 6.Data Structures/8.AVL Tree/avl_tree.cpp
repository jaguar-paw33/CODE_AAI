#include<bits/stdc++.h>
#include"avl_node_class.h"
using namespace std;

/*

Searching, Insertion and Deletion
	Time Complexity - O(logn)
*/

int getHeight(Node<int> * root) {
	if (!root)
		return 0;
	return root->height;
}

int getBalanceFactor(Node<int> * root) {
	if (!root)
		return 0;
	return getHeight(root->left) - getHeight(root->right);
}

Node<int> * leftRotate(Node<int> * cur) {
	Node<int> * root = cur->right;
	Node<int> * temp = root->left;
	root->left = cur;
	cur->right = temp;
	cur->height = 1 + max(getHeight(cur->left), getHeight(cur->right));
	root->height = 1 + max(getHeight(root->left), getHeight(root->right));
	return root;
}

Node<int> * rightRotate(Node<int> * cur) {
	Node<int> * root = cur->left;
	Node<int> * temp = root->right;
	root->right = cur;
	cur->left = temp;
	cur->height = 1 + max(getHeight(cur->left), getHeight(cur->right));
	root->height = 1 + max(getHeight(root->left), getHeight(root->right));
	return root;
}

Node<int> * insert(Node<int> * root, int data) {
	if (!root) {
		return new Node<int>(data);
	}

	if (data < root->data) {
		root->left = insert(root->left, data);
	} else {
		root->right = insert(root->right, data);
	}

	root->height = 1 + max(getHeight(root->left), getHeight(root->right));

	int balanceFactor = getBalanceFactor(root);

	if (balanceFactor < -1) {
		if (data > root->right->data) {
			return leftRotate(root);
		} else {
			root->right = rightRotate(root->right);
			return leftRotate(root);
		}
	} else if (balanceFactor > 1) {
		if (data < root->left->data) {
			return rightRotate(root);
		} else {
			root->left = leftRotate(root->left);
			return rightRotate(root);
		}
	}
	return root;
}

Node<int> * takeInput() {
	int data;
	cin >> data;
	Node<int> * root = NULL;
	while (data != -1) {
		root = insert(root, data);
		cin >> data;
	}
	return root;
}

int findMin(Node<int> * root) {
	Node<int> * temp = root;
	while (temp->left) {
		temp = temp->left;
	}
	return temp->data;
}

Node<int> * deleteNode(Node<int> * root, int key) {
	if (!root)
		return root;
	if (key < root->data) {
		root->left = deleteNode(root->left, key);
	} else if (key > root->data) {
		root->right = deleteNode(root->right, key);
	} else {
		if (!root->left) {
			Node<int> * temp = root;
			root = root->right;
			temp->right = NULL;
			delete temp;
		} else if (!root->right) {
			Node<int> * temp = root;
			root = root->left;
			temp->left = NULL;
			delete temp;
		} else {
			int minValue = findMin(root->right);
			root->data = minValue;
			root->right = deleteNode(root->right, minValue);
		}
	}
	if (!root)
		return root;

	root->height = 1 + max(getHeight(root->left), getHeight(root->right));

	int balanceFactor = getBalanceFactor(root);

	if (balanceFactor < -1) {
		if (getBalanceFactor(root->right) <= 0) {
			return leftRotate(root);
		} else {
			root->right = rightRotate(root->right);
			return leftRotate(root);
		}
	} else if (balanceFactor > 1) {
		if (getBalanceFactor(root->left) >= 0) {
			return rightRotate(root);
		} else {
			root->left = leftRotate(root->left);
			return rightRotate(root);
		}
	}
	return root;
}

void inorder(Node<int> * root) {
	if (!root)
		return;
	inorder(root->left);
	cout << root->data << " ";
	cout << getBalanceFactor(root) << endl;
	inorder(root->right);
}

int main() {
	Node<int> * root;
	root = takeInput();
	inorder(root);
	root = deleteNode(root, 21);
	inorder(root);
	return 0;
}