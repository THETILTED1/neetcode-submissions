const array<pair<int, int>, 4> dir = {{{-1, 0}, {1, 0}, {0, 1}, {0, -1}}};

class Solution{
public:
    int n;
    vector<vector<bool>> mem{};
    bool bounds(vector<vector<int>>& g, int x, int y, int t){
        return 0 <= x and x < n and 0 <= y and y < n
            and !mem[x][y] and g[x][y] <= t;
    }
    bool dfs(vector<vector<int>>& g, int x, int y, int t){
        if (x == n - 1 and y == n - 1)
            return true;
        
        mem[x][y] = true;
        
        for (const auto& d : dir)
            if (bounds(g, x + d.first, y + d.second, t))
                if (dfs(g, x + d.first, y + d.second, t))
                    return true;
        
        return false;
    }
    int swimInWater(vector<vector<int>>& grid) {
        int top = 0;
        n = grid.size();

        mem.resize(n);

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                top = max(top, grid[i][j]);
            
        int l = grid[0][0];
        int r = top;

        while (l < r){
            for (auto& row : mem)
                row.assign(n, false);
            int m = l + (r - l) / 2;
            if (dfs(grid, 0, 0, m))
                r = m;
            else 
                l = m + 1;
        }

        return r;
    }
};
