class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        if(board.size() == 0)
            return true;
            
        int number[10] = {0};
        for(int i = 0; i < 9; ++ i) {
            for(int j = 1; j <= 9; ++ j)
                number[j] = 0;
            for(int j = 0; j < 9; ++ j) {
                if(board[i][j] >= '0' && board[i][j] <= '9') {
                    number[board[i][j] - '0'] ++;
                    if(number[board[i][j] - '0'] > 1)
                        return false;
                }
            }
        }
        for(int i = 0; i < 9; ++ i) {
            for(int j = 1; j <= 9; ++ j)
                number[j] = 0;
            for(int j = 0; j < 9; ++ j) {
                if(board[j][i] >= '0' && board[j][i] <= '9') {
                    number[board[j][i] - '0'] ++;
                    if(number[board[j][i] - '0'] > 1)
                        return false;
                }
            }
        }
        
        for(int i = 0; i < 9; ++ i) {
            for(int j = 1; j <= 9; ++ j)
                number[j] = 0;
            for(int j = 0; j < 3; ++ j)
                for(int k = 0; k < 3; ++ k) {
                    if(board[(i / 3) * 3 + j][(i % 3) * 3 + k] >= '0' && board[(i / 3) * 3 + j][(i % 3) * 3 + k] <= '9') {
                        number[board[(i / 3) * 3 + j][(i % 3) * 3 + k] - '0'] ++;
                        if(number[board[(i / 3) * 3 + j][(i % 3) * 3 + k] - '0'] > 1)
                        return false;
                    }
                }
        }
        
        return true;
    }
};