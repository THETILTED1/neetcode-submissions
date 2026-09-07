class Solution {
public:
    void sink(int a, int b, vector<vector<char>>& g){
        if (a < 0 or a >= g.size()){ return; }
        if (b < 0 or b >= g[0].size()){ return; }
        char& c = g[a][b];
        if (c == '0'){ return; }
        c = '0';
        sink(a + 1, b, g);
        sink(a - 1, b, g);
        sink(a, b + 1, g);
        sink(a, b - 1, g);
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ct = 0;
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                ct += (grid[i][j] == '1');
                sink(i, j, grid);
            }
        }

        return ct;
    }
};
