using Point = pair<int, pair<int, int>>;
const array<pair<int, int>, 4> dir = {{{1, 0}, {-1, 0}, {0, 1}, {0, -1}}};

class Solution {
public:
    vector<vector<bool>> mem{};
    bool bounds(int x, int y, int n){
        return 0 <= x and x < n and 0 <= y and y < n 
            and !mem[x][y];
    }
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        mem.resize(n);
        for (auto& row : mem)
            row.assign(n, false);

        int best = 0;
        priority_queue<Point, vector<Point>, greater<Point>> pq{};
        pq.push({grid[0][0], {0, 0}});

        while (!pq.empty()){
            auto [w, c] = pq.top();
            pq.pop();

            if (mem[c.first][c.second])
                continue;

            mem[c.first][c.second] = true;
            best = max(best, w);

            if (c.first == n - 1 and c.second == n - 1)
                return best;

            for (const auto& d : dir){
                int a = c.first + d.first;
                int b = c.second + d.second;
                if (bounds(a, b, n)){
                    pq.push({grid[a][b], {a, b}});
                    //cout << a << ' ' << b << '\n';
                }
            }
        }

        return 0;        
    }
};
