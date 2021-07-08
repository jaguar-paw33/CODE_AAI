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

	int getMax() {
		if (isEmpty())
			return INT_MIN;
		return pq[0];
	}

	void insert(int data) {
		pq.push_back(data);

		int childIndex = pq.size() - 1;

		while (childIndex > 0) {

			int parentIndex = (childIndex - 1) / 2;

			if (pq[childIndex] > pq[parentIndex]) {
				int temp = pq[parentIndex];
				pq[parentIndex] = pq[childIndex];
				pq[childIndex] = temp;
			} else {
				break;
			}
			childIndex = parentIndex;
		}
	}

	int removeMax() {
		if (isEmpty())
			return INT_MIN;
		int ans = pq[0];
		pq[0] = pq[pq.size() - 1];
		pq.pop_back();

		int parentIndex = 0;
		int lchildIndex = 2 * parentIndex + 1;
		int rchildIndex = 2 * parentIndex + 2;

		while (lchildIndex < pq.size()) {
			int tempIndex = parentIndex;

			if (pq[lchildIndex] > pq[tempIndex])
				tempIndex = lchildIndex;
			if (rchildIndex < pq.size() && pq[rchildIndex] > pq[tempIndex])
				tempIndex = rchildIndex;
			if (parentIndex == tempIndex)
				break;
			int temp = pq[tempIndex];
			pq[tempIndex] = pq[parentIndex];
			pq[parentIndex] = temp;

			parentIndex = tempIndex;
			lchildIndex = 2 * parentIndex + 1;
			rchildIndex = 2 * parentIndex + 2;
		}
		return ans;
	}

};