#include<bits/stdc++.h>
using namespace std;

template <typename T>
class Node {
public:
	T data;
	Node<T> * left;
	Node<T> * right;
	int height;

	Node(T data) {
		this->data = data;
		left = NULL;
		right = NULL;
		height = 1;
	}
};

