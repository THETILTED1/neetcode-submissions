class Solution {
public:
    int sink(int a, int b, vector<vector<int>>& g){
        if (a < 0 or a >= g.size()){ return 0; }
        if (b < 0 or b >= g[0].size()){ return 0; }
        int& c = g[a][b];
        if (c == 0){ return 0; }
        c = 0;
        return 1 + sink(a + 1, b, g) +
        sink(a - 1, b, g) +
        sink(a, b + 1, g) +
        sink(a, b - 1, g);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ct = 0;
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                ct = max(ct, sink(i, j, grid));
            }
        }

        return ct;
    }
};
