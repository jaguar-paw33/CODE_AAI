#include"binary_tree_node.h"

class BST {

	binaryTreeNode<int> * root;

public:

	BST() {
		root = NULL;
	}

	~BST() {
		delete root;
	}

private:

	binaryTreeNode<int> * insert(binaryTreeNode<int> * root, int data) {
		if (!root) {
			binaryTreeNode<int> * newNode = new binaryTreeNode<int>(data);
			return newNode;
		}
		if (root->data >= data) {
			root->left = insert(root->left, data);
		} else {
			root->right = insert(root->right, data);
		}
		return root;
	}


public:

	void insert(int data) {
		root = insert(root, data);
	}

	binaryTreeNode<int> * getRoot() {
		return root;
	}

};

binaryTreeNode<int> * takeInput() {
	BST * b = new BST;
	int rootData;
	cout << "Enter Root Data : ";
	cin >> rootData;
	if (rootData == -1)
		return NULL;
	queue<int> pending;
	pending.push(rootData);
	while (!pending.empty()) {
		int temp = pending.front();
		pending.pop();
		b->insert(temp);
		int lChild;
		cout << "Enter Left Child : ";
		cin >> lChild;
		if (lChild != -1) {
			pending.push(lChild);
		}
		int rChild;
		cout << "Enter Right Child : ";
		cin >> rChild;
		if (rChild != -1) {
			pending.push(rChild);
		}
	}
	return b->getRoot();
}

binaryTreeNode<int> * deleteNode(binaryTreeNode<int> * root, int data) {
	if (!root)
		return root;
	if (root->data > data) {
		root->left = deleteNode(root->left, data);
	} else if (root->data < data) {
		root->right = deleteNode(root->right, data);
	} else {
		if (!root->right) {
			binaryTreeNode<int> * temp = root;
			root = root->left;
			temp->left = NULL;
			delete temp;
		} else if (!root->left && !root->right) {
			delete root;
			root = NULL;
		} else {
			binaryTreeNode<int> * temp = root->right;
			while (temp->left) {
				temp = temp->left;
			}
			root->data = temp->data;
			root->right = deleteNode(root->right, temp->data);
		}
	}
	return root;
}

void printTree(binaryTreeNode<int>* root) {
	if (!root)
		return;
	queue<binaryTreeNode<int>*> pending;
	pending.push(root);
	while (!pending.empty()) {
		binaryTreeNode<int>* temp = pending.front();
		pending.pop();
		cout << temp->data << ":";
		if (temp->left) {
			cout << "L:" << temp->left->data << ",";
			pending.push(temp->left);
		} else {
			cout << "L:" << -1 << ",";
		}
		if (temp->right) {
			cout << "R:" << temp->right->data;
			pending.push(temp->right);
		} else {
			cout << "R:" << -1;
		}
		cout << endl;
	}
}
