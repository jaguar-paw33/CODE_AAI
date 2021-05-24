#include<bits/stdc++.h>
#include"hash_map.h"
using namespace std;


int main() {
	ourmap<int> m;
	for (int i = 0; i < 10; i++) {
		string key = "a";
		char c = i + 48;
		m.insert(key + c, i + 1);
	}
	for (int i = 0; i < 10; i++) {
		string key = "a";
		char c = i + 48;
		cout << m.getValue(key + c) << " ";
	}
	return 0;
}