/* 
* @Author: Zeyuan Shang
* @Date:   2015-11-05 00:18:39
* @Last Modified by:   Zeyuan Shang
* @Last Modified time: 2015-11-05 00:18:57
*/

class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode() : children(26, NULL), isWord(false) {
    }
    vector<TrieNode*> children;
    bool isWord;
};

class WordDictionary {
private:
    TrieNode* root;
    
    bool recursive_serach(TrieNode* p, string word) {
        if (word.length() == 0) {
            return p->isWord;
        }
        char c = word[0];
        if (c != '.') {
            if (!p->children[c - 'a']) {
                return false;
            }
            return recursive_serach(p->children[c - 'a'], word.substr(1));
        } else {
            bool ret = false;
            for (char x = 'a'; x <= 'z'; ++x) {
                if (!p->children[x - 'a']) {
                    continue;
                }
                ret |= recursive_serach(p->children[x - 'a'], word.substr(1));
                if (ret) {
                    return true;
                }
            }
        }
        return false;
    }
public:
    WordDictionary() {
        root = new TrieNode();
    }

    // Adds a word into the data structure.
    void addWord(string word) {
        TrieNode* p = root;
        for (auto c : word) {
            if (!p->children[c - 'a']) {
                p->children[c - 'a'] = new TrieNode();
            }
            p = p->children[c - 'a'];
        }
        p->isWord = true;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        return recursive_serach(root, word);
    }
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");