class Solution {
public:
    int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};

    void bfs(vector<vector<char>> &board, queue<pair<int, int>> &q) {
        while(!q.empty()) {
            int x = q.front().first, y = q.front().second;
            q.pop();
            board[x][y] = 'C';
            for(int i = 0; i < 4; ++ i) {
                int xx = x + dx[i], yy = y + dy[i];
                if(xx < 0 || xx >= board.size() || yy < 0 || yy >= board[0].size() || board[xx][yy] != 'O')
                    continue;
                board[xx][yy] = 'X';
                q.push(make_pair(xx, yy));
            }
        }
    }

    void solve(vector<vector<char>> &board) {
        if(board.empty())
            return;
        
        queue<pair<int, int>> q;
        int n = board.size(), m = board[0].size();
        for(int i = 0; i < n; ++ i) {
            if(board[i][0] == 'O') {
                board[i][0] = 'X';
                q.push(make_pair(i, 0));
                bfs(board, q);
            }
            if(board[i][m - 1] == 'O') {
                board[i][m - 1] = 'X';
                q.push(make_pair(i, m - 1));
                bfs(board, q);
            }
        }
        for(int i = 0; i < m; ++ i) {
            if(board[0][i] == 'O') {
                board[0][i] = 'X';
                q.push(make_pair(0, i));
                bfs(board, q);
            }
            if(board[n - 1][i] == 'O') {
                board[n - 1][i] = 'X';
                q.push(make_pair(n - 1, i));
                bfs(board, q);
            }
        }
        for(int i = 0; i < n; ++ i)
            for(int j = 0; j < m; ++ j) {
                if(board[i][j] == 'O')
                    board[i][j] = 'X';
                if(board[i][j] == 'C')
                    board[i][j] = 'O';
            }
    }
};