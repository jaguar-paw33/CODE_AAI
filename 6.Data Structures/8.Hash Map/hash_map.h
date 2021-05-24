#include<bits/stdc++.h>
using namespace std;


template<typename V>
class MapNode {

public:

	string key;
	V value;
	MapNode<V> * next;

	MapNode(string key, V value) {
		this->key = key;
		this->value = value;
		this->next = NULL;
	}

	~MapNode() {
		delete next;
	}

};


template <typename V>
class ourmap {

	MapNode<V> ** buckets;
	int size;
	int numBuckets;

public:

	ourmap() {

		size = 0;
		numBuckets  = 5;
		buckets = new MapNode<V> * [numBuckets];

		for (int i = 0; i < numBuckets; i++) {
			buckets[i] = NULL;
		}

	}

	int getSize() {
		return size;
	}

private:

	int getBucketIndex(string key) {

		int code = 0;
		int exp = 1;

		for (int i = key.size() - 1; i >= 0; i--) {
			code += int(key[i]) * exp;
			code %= numBuckets;
			exp *= 31;
			exp %= numBuckets;
		}

		return code % numBuckets;
	}

	float load_factor() {
		return (float)size / numBuckets;
	}

	void rehash() {

		MapNode<V> ** temp = buckets;
		int oldNumBuckets = numBuckets;

		numBuckets *= 2;
		buckets = new MapNode<V> * [numBuckets];

		for (int i = 0; i < numBuckets; i++) {
			buckets[i] = NULL;
		}

		size = 0;

		for (int i = 0; i < oldNumBuckets; i++) {
			MapNode<V> * head = temp[i];
			while (head) {
				insert(head->key, head->value);
				head = head->next;
			}
		}

		for (int i = 0; i < oldNumBuckets; i++) {
			MapNode<V> * head = temp[i];
			delete head;
		}

		delete [] temp;
	}

public:

	V getValue(string key) {

		int index = getBucketIndex(key);

		MapNode<V> * head = buckets[index];

		while (head) {
			if (head->key == key) {
				return head->value;
			}
			head = head->next;
		}

		return -1;
	}

	void insert(string key, V value) {

		int index = getBucketIndex(key);

		MapNode<V> * newNode = new MapNode<V>(key, value);
		MapNode<V> * head = buckets[index];
		MapNode<V> * tail = head;

		while (tail) {
			if (tail->key == key) {
				tail->value = value;
				return;
			}
			tail = tail->next;
		}

		newNode->next = head;
		buckets[index] = newNode;
		size++;

		if (load_factor() > 0.7) {
			rehash();
		}

		return;
	}

	V remove(string key) {

		int index = getBucketIndex(key);

		MapNode<V> * cur = buckets[index];
		MapNode<V> * prev = NULL;

		while (cur) {
			if (cur->key == key) {
				V ans = cur->data;
				if (!prev) {
					buckets[index] = cur->next;
				} else {
					prev->next = cur->next;
				}
				cur->next = NULL;
				delete cur;
				size--;
				return ans;
			}
			prev = cur;
			cur = cur->next;
		}

		return -1;
	}

	~ourmap() {

		for (int i = 0; i < numBuckets; i++) {
			delete buckets[i];
		}

		delete [] buckets;
	}

};