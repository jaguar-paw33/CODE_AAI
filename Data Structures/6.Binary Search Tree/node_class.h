#include<bits/stdc++.h>
using namespace std;

template<typename T>
class Node{

public:

	T data;
	Node<T>* next;

	Node(T data) {
		this->data = data;
		this->next = NULL;
	}

};
