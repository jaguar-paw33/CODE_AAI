#include<bits/stdc++.h>
#include"linked_list.h"
using namespace std;

int length_LL(Node<int> * head) {
	if (!head)
		return 0;
	return 1 + length_LL(head->next);
}

int main() {
	Node<int> * head = takeInput();
	printLL(head);
	cout << endl << "Length : " << length_LL(head);
	return 0;
}
