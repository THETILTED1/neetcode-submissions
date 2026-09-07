class Solution {
public:
    bool bounds(pair<int, int> cds, vector<vector<int>>& g){
        return cds.first >= 0 and cds.first < g.size()
            and cds.second >= 0 and cds.second < g[0].size()
            and g[cds.first][cds.second] != -1
            and g[cds.first][cds.second] == INT_MAX;
    }
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<int, int>> q{};

        for (int i = 0; i < grid.size(); i++){
            for (int j = 0; j < grid[0].size(); j++){
                if (grid[i][j] == 0){
                    q.push({i, j});
                }
            }
        }

        while (!q.empty()){
            auto [i, j] = q.front();
            q.pop();

            array<pair<int, int>, 4> ar = {{{i+1,j}, {i-1,j},
                                     {i,j+1}, {i,j-1}}};
            for (pair<int, int> s : ar){
                if (!bounds(s, grid)){ continue; }
                grid[s.first][s.second] = grid[i][j] + 1;
                q.push(s);
            }
        }
    }
};
