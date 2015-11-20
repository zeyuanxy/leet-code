/* 
* @Author: Zeyuan Shang
* @Date:   2015-11-19 19:26:22
* @Last Modified by:   Zeyuan Shang
* @Last Modified time: 2015-11-19 19:26:32
*/

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

    bool search(vector<char>& word) {
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
    
    bool startsWith(vector<char>& prefix) {
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

class Solution {
public:
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    void dfs(vector<vector<char>>& board, int x, int y, vector<pair<int, int>>& pos, vector<char>& str, vector<string>& words, Trie& trie, set<string>& ans) {
        if (!trie.startsWith(str)) {
            return;
        }
        if (trie.search(str)) {
            string s = "";
            for (auto c : str) {
                s += c;
            }
            ans.insert(s);
        }
        int n = board.size(), m = board[0].size();
        for (int i = 0; i < 4; ++i) {
            int xx = x + dx[i], yy = y + dy[i];
            if (xx >= 0 && xx < n && yy >= 0 && yy < m) {
                bool dup = false;
                for (auto pp : pos) {
                    if (pp.first == xx && pp.second == yy) {
                        dup = true;
                        break;
                    }
                }
                if (!dup) {
                    str.push_back(board[xx][yy]);
                    pos.push_back(make_pair(xx, yy));
                    dfs(board, xx, yy, pos, str, words, trie, ans);
                    pos.pop_back();
                    str.pop_back();
                }
            }
        }
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie trie;
        for (string word : words) {
            trie.insert(word);
        }
        set<string> ans;
        int n = board.size(), m = board[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                vector<pair<int, int>> pos;
                pos.push_back(make_pair(i, j));
                vector<char> str;
                str.push_back(board[i][j]);
                dfs(board, i, j, pos, str, words, trie, ans);
            }
        }
        vector<string> ret;
        for (string s : ans) {
            ret.push_back(s);
        }
        return ret;
    }
};