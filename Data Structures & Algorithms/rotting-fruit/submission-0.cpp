struct Coords{
    int r;
    int c;
    int l;
};

class Solution {
public:
    bool inBounds(vector<vector<int>>& g, const Coords& bb){
        return (bb.r >= 0) and (bb.r < g.size())
            and (bb.c >= 0) and (bb.c < g[0].size());
    }
    bool isFruit(vector<vector<int>>& g, const Coords& bb){
        return inBounds(g, bb) and (g[bb.r][bb.c] == 1);
    }

    int orangesRotting(vector<vector<int>>& grid) {
        int good = 0;

        queue<Coords> q{};

        int m = grid.size();
        int n = grid[0].size();

        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (grid[i][j] == 2){
                    q.push({i, j, 0});
                    grid[i][j] = 1;
                }
                good += grid[i][j];
            }
        }

        int ll = 0;

        while (!q.empty()){
            Coords bb = q.front();
            q.pop();

            if (isFruit(grid, bb)){
                grid[bb.r][bb.c] = 0;
                good--;
                ll = max(ll, bb.l);

                q.push({bb.r + 1, bb.c, bb.l + 1});
                q.push({bb.r - 1, bb.c, bb.l + 1});
                q.push({bb.r, bb.c + 1, bb.l + 1});
                q.push({bb.r, bb.c - 1, bb.l + 1});
            }
        }

        if (good > 0){ return -1; }
        return ll;
    }
};
