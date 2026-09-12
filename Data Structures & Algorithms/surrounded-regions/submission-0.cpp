class Solution {
public:
    int m, n;
    
    bool bounds(int x, int y){
        return x >= 0 and x < m
            and y >= 0 and y < n;
    }

    void save(vector<vector<char>>& g, int x, int y){
        if (!bounds(x, y) or g[x][y] != 'O')
            return;

        g[x][y] = 'P';
        
        save(g, x + 1, y);
        save(g, x - 1, y);
        save(g, x, y + 1);
        save(g, x, y - 1);
    }

    void solve(vector<vector<char>>& board) {
        m = board.size();
        n = board[0].size();

        for (int i = 0; i < m; i++){
            save(board, i, 0);
            save(board, i, n - 1);
        }
        for (int i = 1; i < n - 1; i++){
            save(board, 0, i);
            save(board, m - 1, i);
        }

        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                if (board[i][j] == 'P')
                    board[i][j] = 'O';
            }
        }
    }
};
