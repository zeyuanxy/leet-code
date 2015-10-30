class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode() : children(26, NULL), isWord(false) {
    }
    vector<TrieNode*> children;
    bool isWord;
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode* p = root;
        for (auto c : word) {
            if (!p->children[c - 'a']) {
                p->children[c - 'a'] = new TrieNode();
            }
            p = p->children[c - 'a'];
        }
        p->isWord = true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode* p = root;
        for (auto c : word) {
            if (!p->children[c - 'a']) {
                return false;
            }
            p = p->children[c - 'a'];
        }
        return p->isWord;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode* p = root;
        for (auto c : prefix) {
            if (!p->children[c - 'a']) {
                return false;
            }
            p = p->children[c - 'a'];
        }
        return true;
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");