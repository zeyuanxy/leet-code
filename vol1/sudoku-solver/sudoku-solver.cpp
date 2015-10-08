class Solution {
private:
    bool row[9][10], col[9][10], blk[9][10];
public:
    bool solve(vector<vector<char> > &board) {
        for(int x = 0; x < 9; ++ x)
            for(int y = 0; y < 9; ++ y)
                if(board[x][y] == '.') {
                    for(int i = 1; i <= 9; ++ i)
                        if(!row[x][i] && !col[y][i] && !blk[(x / 3) * 3 + y / 3][i]) {
                            board[x][y] = '0' + i;
                            row[x][i] = true;
                            col[y][i] = true;
                            blk[(x / 3) * 3 + y / 3][i] = true;
                            if(solve(board))
                                return true;
                            board[x][y] = '.';
                            row[x][i] = false;
                            col[y][i] = false;
                            blk[(x / 3) * 3 + y / 3][i] = false;
                        }
                    return false;
                }
        return true;
    }

    void solveSudoku(vector<vector<char> > &board) {
        for(int i = 0; i < 9; ++ i)
            for(int j = 1; j <= 9; ++ j) {
                row[i][j] = false;
                col[i][j] = false;
                blk[i][j] = false;
            }
        for(int x = 0; x < 9; ++ x)
            for(int y = 0; y < 9; ++ y)
                if(board[x][y] != '.') {
                    row[x][board[x][y] - '0'] = true;
                    col[y][board[x][y] - '0'] = true;
                    blk[(x / 3) * 3 + y / 3][board[x][y] - '0'] = true;
                }
        solve(board);
    }
};