class Solution {
public:
    int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
    bool inWord[1000][1000];

    bool search(vector<vector<char> > &board, int x, int y, string word) {
        inWord[x][y] = true;
        if(word.size() == 0)
            return true;
        for(int i = 0; i < 4; ++ i) {
            int xx = x + dx[i], yy = y + dy[i];
            if(xx >= 0 && xx < board.size() && yy >= 0 && yy < board[0].size() && board[xx][yy] == word[0] && !inWord[xx][yy] && search(board, xx, yy, word.substr(1)))
                return true;
        }
        inWord[x][y] = false;
        return false;
    }

    bool exist(vector<vector<char> > &board, string word) {
        if(board.empty() || word.size() == 0)
            return false;
        
        memset(inWord, false, sizeof(bool) * board.size() * board[0].size());
        for(int i = 0; i < board.size(); ++ i)
            for(int j = 0; j < board[0].size(); ++ j)
                if(board[i][j] == word[0] && search(board, i, j, word.substr(1)))
                    return true;
        return false;
    }
};