/*

A linked list of length n is given such that each node contains an additional random pointer, which could point to any node in the list, or null.

Construct a deep copy of the list. The deep copy should consist of exactly n brand new nodes, where each new node has its value set to the value of its corresponding original node. Both the next and random pointer of the new nodes should point to new nodes in the copied list such that the pointers in the original list and copied list represent the same list state. None of the pointers in the new list should point to nodes in the original list.

For example, if there are two nodes X and Y in the original list, where X.random --> Y, then for the corresponding two nodes x and y in the copied list, x.random --> y.

Return the head of the copied linked list.

The linked list is represented in the input/output as a list of n nodes. Each node is represented as a pair of [val, random_index] where:

val: an integer representing Node.val
random_index: the index of the node (range from 0 to n-1) that the random pointer points to, or null if it does not point to any node.
Your code will only be given the head of the original linked list.



Example 1:


Input: head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
Output: [[7,null],[13,0],[11,4],[10,2],[1,0]]
Example 2:


Input: head = [[1,1],[2,1]]
Output: [[1,1],[2,1]]
Example 3:



Input: head = [[3,null],[3,0],[3,null]]
Output: [[3,null],[3,0],[3,null]]
Example 4:

Input: head = []
Output: []
Explanation: The given linked list is empty (null pointer), so return null.


Constraints:

0 <= n <= 1000
-10000 <= Node.val <= 10000
Node.random is null or is pointing to some node in the linked list.

Practise Problem Link - https://leetcode.com/problems/copy-list-with-random-pointer/

*/




// Time Complexity - O(n) and Space Complexity - O(n)
Node* copyRandomList1(Node* head) {

	Node * nh = NULL, * nt = NULL;
	Node * cur = head;
	unordered_map<Node *, int> raw_addr_idx;

	int i = 0;
	while (cur) {

		Node * newNode = new Node(cur->val);

		if (!nh) {
			nh = newNode;
			nt = newNode;
		} else {
			nt->next = newNode;
			nt = newNode;
		}

		raw_addr_idx[cur] = i++;
		cur = cur->next;
	}

	vector<int> raw_idx;
	cur = head;

	while (cur) {
		if (cur->random)
			raw_idx.push_back(raw_addr_idx[cur->random]);
		else
			raw_idx.push_back(-1);
		cur = cur->next;
	}

	unordered_map<int, Node *> new_idx_addr;
	cur = nh;
	i = 0;

	while (cur) {
		new_idx_addr[i++] = cur;
		cur = cur->next;
	}

	cur = nh;
	i = 0;

	while (cur) {
		if (raw_idx[i] != -1)
			cur->random = new_idx_addr[raw_idx[i]];
		else
			cur->random = NULL;
		i++;
		cur = cur->next;
	}

	return nh;
}



// Time Complexity - O(n) and Space Complexity - O(1)

// Create copy of nodes in the same linkd list
Node* copyRandomList2(Node* head) {

	if (!head)
		return NULL;

	Node * cur = head;

	while (cur) {
		Node * newNode = new Node (cur->val);
		newNode->next = cur->next;
		cur->next = newNode;
		cur = cur->next->next;
	}

	cur = head;

	while (cur && cur->next) {
		if (cur->random)
			cur->next->random = cur->random->next;
		cur = cur->next->next;
	}

	cur = head;
	Node * nh = cur->next;

	while (cur && cur->next) {
		Node * temp = cur->next;
		cur->next = cur->next->next;
		cur = temp;
	}

	return nh;
}


