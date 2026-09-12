class Solution {
public:
    int m, n;

    bool bounds(int x, int y){
        return x >= 0 and x < m 
            and y >= 0 and y < n;
    }

    bool dfs(vector<vector<char>>& g, string& w, int l, int x, int y){
        if (l == w.size())
            return true;

        if (!bounds(x, y) or g[x][y] != w[l])
            return false;

        char tmp = g[x][y];
        g[x][y] = '#';

        bool is = dfs(g, w, l + 1, x + 1, y)
            or dfs(g, w, l + 1, x - 1, y)
            or dfs(g, w, l + 1, x, y + 1)
            or dfs(g, w, l + 1, x, y - 1);

        g[x][y] = tmp;

        return is;
    }

    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (dfs(board, word, 0, i, j)){
                    return true;
                }
            }
        }
        return false;
    }
};
