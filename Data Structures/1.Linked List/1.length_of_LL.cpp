#include<bits/stdc++.h>
#include"linked_list.h"
using namespace std;

int length_LL(Node<int> * head) {
	Node<int> * temp = head;
	int l = 0;
	while (temp) {
		l++;
		temp = temp->next;
	}
	return l;
}

int main() {
	Node<int> * head = takeInput();
	printLL(head);
	cout << endl << "Length : " << length_LL(head) << endl;
	return 0;
}
