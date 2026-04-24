// Last updated: 4/24/2026, 10:17:18 PM
#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <climits>
using namespace std;

class TrieNode {
public:
    unordered_map<char, TrieNode*> children;

    TrieNode() {}
};

class Trie {
private:
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }

    void addWord(const string& word) {
        TrieNode* curr = root;
        for (char ch : word) {
            if (curr->children.find(ch) == curr->children.end()) {
                curr->children[ch] = new TrieNode();
            }
            curr = curr->children[ch];
        }
    }

    int search(const string& word) {
        TrieNode* curr = root;
        int prefix_len = 0;

        for (char ch : word) {
            if (curr->children.size() != 1) {
                return prefix_len;
            }
            prefix_len++;
            curr = curr->children[ch];
        }
        return prefix_len;
    }
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";

        Trie trie;
        int prefix_len = INT_MAX;

        for (const string& word : strs) {
            trie.addWord(word);
        }

        for (const string& word : strs) {
            prefix_len = min(prefix_len, trie.search(word));
        }

        return strs[0].substr(0, prefix_len);
    }
};