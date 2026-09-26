array<pair<int, int>, 4> dir = {{{1, 0}, {-1, 0}, {0, 1}, {0, -1}}};

class Solution {
public:
    int m, n;
    bool bounds(int x, int y){
        return 0 <= x and x < m and 0 <= y and y < n;
    }
    int dfs(vector<vector<int>>& g, vector<vector<int>>& mem, int x, int y){
        if (mem[x][y])
            return mem[x][y];
        int r = 0;        
        for (const auto& d : dir){
            int a = x + d.first;
            int b = y + d.second;
            if (bounds(a, b) and g[a][b] > g[x][y])
                r = max(r, dfs(g, mem, a, b));
        }
        mem[x][y] = 1 + r;
        return 1 + r;      
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int best = 0;

        m = matrix.size();
        n = matrix[0].size();

        vector<vector<int>> mem(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                best = max(best, dfs(matrix, mem, i, j));
            
        return best;
    }
};
