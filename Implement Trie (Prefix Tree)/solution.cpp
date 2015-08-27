#include <iostream>
#include <string>
#include <string.h>
using namespace std;


class TrieNode {
public:
	// Initialize your data structure here.
	TrieNode() {
		memset(array, 0, sizeof(array)); 
		isWord = false;
	}
	TrieNode* array[26];
	bool isWord;
};

class Trie {
public:
	Trie() {
		root = new TrieNode();
	}

	// Inserts a word into the trie.
	void insert(string word) {
		auto tmp = root;
		for (const auto& c : word)
		{
			if (tmp->array[c - 'a'] == NULL)
			{
				tmp->array[c - 'a'] = new TrieNode();
			}
			tmp = tmp->array[c - 'a'];
		} 
		tmp->isWord = true;
	}

	// Returns if the word is in the trie.
	bool search(string word) {
		auto tmp = root;
		for (const auto& c : word)
		{
			if (tmp->array[c - 'a'] == NULL)
			{
				return false;
			}
			tmp = tmp->array[c - 'a'];
		}
		if (tmp->isWord)
		{
			return true;
		}
		return false;
	}

	// Returns if there is any word in the trie
	// that starts with the given prefix.
	bool startsWith(string prefix) {
		auto tmp = root;
		for (const auto& c : prefix)
		{
			if (tmp->array[c - 'a'] == NULL)
			{
				return false;
			}
			tmp = tmp->array[c - 'a'];
		}
		return true;
	}

private:
	TrieNode* root;
	TrieNode* end;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");

int main()
{	
	Trie t;
	t.insert("helloworld");
	t.insert("hellow");
	t.insert("aaaa");
	cout << t.search("hello") << endl;
	cout << t.search("world") << endl;
	cout << t.search("helloworld") << endl;
	cout << t.startsWith("hello") << endl;
	return 0;
}
