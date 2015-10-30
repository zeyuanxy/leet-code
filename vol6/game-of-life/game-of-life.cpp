class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        if (board.empty()) {
            return;
        }
        int n = board.size(), m = board[0].size();
        int dx[8] = {1, 1, 1, 0, 0, -1, -1, -1};
        int dy[8] = {1, 0, -1, 1, -1, 1, 0, -1};
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int cnt = 0;
                for (int k = 0; k < 8; ++k) {
                    int x = i + dx[k], y = j + dy[k];
                    if (x >= 0 && x < n && y >= 0 && y < m && board[x][y] % 2 == 1) {
                        ++cnt;
                    }
                }
                
                int status = board[i][j];
                if (status == 1) {
                    if (cnt < 2 || cnt > 3) {
                        status = 0;
                    }
                } else {
                    if (cnt == 3) {
                        status = 1;
                    }
                }
                
                board[i][j] = status * 2 + board[i][j];
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                board[i][j] /= 2;
            }
        }
    }
};