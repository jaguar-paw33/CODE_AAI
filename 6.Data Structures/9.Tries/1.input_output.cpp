#include<bits/stdc++.h>
#include"trie.h"
using namespace std;

int main() {
	Trie t;
	t.insert("done");
	t.insert("do");

	cout << t.search("done") << endl;
	cout << t.search("do") << endl;

	t.remove("done");
	cout << t.search("done") << endl;
	t.remove("do");
	cout << t.search("do") << endl;

	return 0;
}