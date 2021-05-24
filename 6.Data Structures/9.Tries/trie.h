#include<bits/stdc++.h>
#include"trie_node.h"
using namespace std;

class Trie {

	TrieNode * root;

public:

	Trie() {
		root = new TrieNode('\0');
	}

	~Trie() {
		delete root;
	}

private:

	void insert(string s, TrieNode * root) {
		if (!s.size()) {
			root->isTerminal = true;
			return;
		}
		int index = s[0] - 'a';
		if (!root->children[index]) {
			root->children[index] = new TrieNode(s[0]);
		}
		insert(s.substr(1), root->children[index]);
	}

	bool search(string s, TrieNode * root) {
		if (!s.size()) {
			return root->isTerminal;
		}
		int index = s[0] - 'a';
		if (!root->children[index])
			return false;
		return search(s.substr(1), root->children[index]);
	}

	void remove(string s, TrieNode * root) {
		if (!s.size()) {
			root->isTerminal = false;
			return;
		}
		int index = s[0] - 'a';
		if (!root->children[index])
			return;
		remove(s.substr(1), root->children[index]);
		bool remove_child = true;
		for (int i = 0; i < 26 ; i++) {
			if (!root->children[index]->isTerminal || root->children[index]->children[i]) {
				remove_child = false;
				break;
			}
		}
		if (remove_child) {
			delete root->children[index];
			root->children[index] = NULL;
		}
	}

	bool find_pattern(string pattern, TrieNode * root) {
		if (!pattern.size())
			return true;
		int index = pattern[0] - 'a';
		if (!root->children[index])
			return false;
		return find_pattern(pattern.substr(1), root->children[index]);
	}

	bool is_palindrome(string word) {
		for (int i = 0, j = word.size() - 1; i < j; i++, j--) {
			if (word[i] != word[j])
				return false;
		}
		return true;
	}

	void rev(string & word) {
		for (int i = 0, j = word.size() - 1; i < j; i++, j--) {
			char c = word[j];
			word[j] = word[i];
			word[i] = c;
		}
	}

	bool is_palindrome_present(vector<string> & words) {
		bool is_present = false;
		for (int i = 0; i < words.size(); i++) {
			string word = words[i];
			rev(word);
			is_present = search(word);
			if (is_present)
				return true;
		}
		return false;
	}

	void auto_complete(string pattern, TrieNode * root, string word) {
		if (!root)
			return;
		if (pattern.size()) {
			int index = pattern[0] - 'a';
			auto_complete(pattern.substr(1), root->children[index], word + pattern[0]);
		}
		else {
			if (root->isTerminal)
				cout << word << endl;
			for (int i = 0; i < 26; i++) {
				if (root->children[i])
					auto_complete(pattern, root->children[i], word + root->children[i]->data);
			}
		}
	}


public:

	void insert(string s) {
		insert(s, root);
	}

	bool search(string s) {
		return search(s, root);
	}

	void remove(string s) {
		remove(s, root);
	}

	bool find_pattern(vector<string> & words, string pattern) {
		for (int i = 0; i < words.size(); i++) {
			string word = words[i];
			for (int i = 0; i < word.size(); i++) {
				insert(word.substr(i));
			}
		}
		return find_pattern(pattern, root);
	}

	bool palindrome_pair(vector<string> & words) {
		for (int i = 0; i < words.size(); i++) {
			insert(words[i].substr(1));
			insert(words[i]);
			insert(words[i].substr(0, words[i].size() - 1));
			if (is_palindrome(words[i]))
				return true;
		}
		return is_palindrome_present(words);
	}

	void auto_complete(vector<string> words, string pattern) {
		for (int i = 0; i < words.size(); i++) {
			insert(words[i]);
		}
		auto_complete(pattern, root, "");
	}

};