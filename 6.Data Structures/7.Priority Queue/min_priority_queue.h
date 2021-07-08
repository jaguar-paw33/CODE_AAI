
/*

To Implement the Priority Queue the most optimal data structure is a Bianry Tree which takes O(h) time for
insert, delete and getMin operations. Now, if the tree is not balanced the hieght can become O(n) and hence
worsening the time complexity of each operation. Now, in order to keep these operation in optimal Time Complexity
we need to keep the tree balanced and to get such implementation we make use of a new data structrue called Heap
Heap which has the following two characterstics,

1. Heap is a Complete Binary Tree, which is basically a Binary Tree in which new child
   can be inserted at the last level only and that also from left to right and the deletion
   can only be performed on the last node from left to right of the last level to maintain the CBT structure.

Example-

      3                6
    /   \            /   \
   2     4          2     4
  / \   / \        / \   / \
 8  12 3          8  12     5

	 CBT           Not a CBT

The CBT is always balanced since the height of a CBT in worst case if O(logn) where n is the number of nodes.

Proof :-

Minimum Number of Nodes in a CBT of height h = 2^(h-1)
Maximum Number of Nodes in a CBT of height h = 2^h - 1

Now, for a CBT having n nodes and height h,

2^(h-1) <= n <= 2^h - 1

Solving this we get h = O(logn).

2. Heap also has a Heap Order Property which basically means that the children are smaller than the parent
   if we have min heap or the child nodes must be greater than the parent node if we use Max Heap.


Now, to implement Heap we store the CBT in the form of Array instead of stroing it in the form of Binary Tree and
how it is exactly done is shown below.

*/


#include<bits/stdc++.h>
using namespace std;

class PriorityQueue {

	vector<int> pq;

public:

	bool isEmpty() {
		return !pq.size();
	}

	int getSize() {
		return pq.size();
	}

	int getMin() {
		if (isEmpty()) {
			cout << "Heap is Empty" << endl;
			return -1;
		}
		return pq[0];
	}

	void insert(int data) {

		pq.push_back(data);

		int childIndex = pq.size() - 1;

		while (childIndex > 0) {

			int parentIndex = (childIndex - 1) / 2;

			if (pq[childIndex] < pq[parentIndex]) {
				int temp = pq[parentIndex];
				pq[parentIndex] = pq[childIndex];
				pq[childIndex] = temp;
			} else {
				break;
			}

			childIndex = parentIndex;

		}
	}



	int removeMin() {
		if (isEmpty()) {
			cout << "Heap is Empty" << endl;
			return -1;
		}

		int ans = pq[0];
		pq[0] = pq[pq.size() - 1];
		pq.pop_back();

		int parentIndex = 0;
		int lchildIndex = (2 * parentIndex + 1);
		int rchildIndex = (2 * parentIndex + 2);

		while (lchildIndex < pq.size()) {

			int tempIndex = parentIndex;

			if (pq[lchildIndex] < pq[tempIndex])
				tempIndex = lchildIndex;
			if (rchildIndex < pq.size() && pq[rchildIndex] < pq[tempIndex])
				tempIndex = rchildIndex;

			if (parentIndex == tempIndex)
				break;

			int temp = pq[tempIndex];
			pq[tempIndex] = pq[parentIndex];
			pq[parentIndex] = temp;

			parentIndex = tempIndex;
			lchildIndex = (2 * parentIndex + 1);
			rchildIndex = (2 * parentIndex + 2);
		}

		return ans;
	}
};
