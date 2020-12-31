#include <bits/stdc++.h>
using namespace std;

class TrieNode {
public:
	bool exists = false;
	TrieNode* child[26];
	void insert(string s) {
		if (s == "") {
			this->exists = true;
			return;
		}
		int k = s[0]-'a';
		if (this->child[k] == nullptr) {
			this->child[k] = new TrieNode();
		}
		this->child[k]->insert(s.substr(1));
	}
	bool search(string s) {
		if (s == "") {
			return this->exists;
		}
		int k = s[0]-'a';
		if (this->child[k] == nullptr) {
			return false;
		}
		return this->child[k]->search(s.substr(1));
	}
	bool startsWith(string s) {
		if (s == "") {
			return true;
		}
		int k = s[0]-'a';
		if (this->child[k] == nullptr) {
			return false;
		}
		return this->child[k]->startsWith(s.substr(1));
	}
	void del(string s) {
		if (s == "") {
			this->exists = false;
			return;
		}
		int k = s[0]-'a';
		if (this->child[k] == nullptr) {
			return;
		}
		this->child[k]->del(s.substr(1));
		if (!this->child[k]->hasChild()) {
			delete this->child[k];
			this->child[k] = nullptr;
		}
	}
	bool hasChild() {
		for(int i = 0; i < 26; i++) {
			if (this->child[i] != nullptr) {
				return true;
			}
		}
		return false;
	}
};

class Trie {
public:
	TrieNode* root;
	Trie() {
		this->root = new TrieNode();
	}
	void insert(string s) {
		// better not to do recursive implementation, since substr function is linear time 
		// and paramter passing is also call-by-value
		this->root->insert(s);
	}
	bool search(string s) {
		return this->root->search(s);
	}
	bool startsWith(string s) {
		return this->root->startsWith(s);
	}
	void del(string s) {
		this->root->del(s);
	}
};

int main() {
	Trie *t = new Trie();
	t->insert("abc");
	cout << t->search("abc") << "\n";
	cout << t->search("ab") << "\n";
	cout << t->startsWith("ab") << "\n";
	cout << t->startsWith("ac") << "\n";
	t->insert("ab");
	cout << t->search("ab") << "\n";
	cout << t->startsWith("ab") << "\n";
	t->del("abc");
	cout << t->search("ab") << "\n";
	cout << t->search("abc") << "\n";
	return 0;
}