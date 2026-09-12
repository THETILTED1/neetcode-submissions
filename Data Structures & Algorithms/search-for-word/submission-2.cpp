class Solution {
public:
    int m, n;

    bool bounds(int x, int y){
        return x >= 0 and x < m 
            and y >= 0 and y < n;
    }

    bool dfs(vector<vector<char>>& g, unordered_set<int>& sn, 
        string& w, int l, int x, int y){

        if (l == w.size())
            return true;

        if (!bounds(x, y) or g[x][y] != w[l]
                or sn.contains(x * n + y))
            return false;

        sn.insert(x * n + y);

        bool is = dfs(g, sn, w, l + 1, x + 1, y)
            or dfs(g, sn, w, l + 1, x - 1, y)
            or dfs(g, sn, w, l + 1, x, y + 1)
            or dfs(g, sn, w, l + 1, x, y - 1);

        sn.erase(x * n + y);

        return is;
    }

    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();
        unordered_set<int> sn{};
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (dfs(board, sn, word, 0, i, j)){
                    return true;
                }
            }
        }
        return false;
    }
};
