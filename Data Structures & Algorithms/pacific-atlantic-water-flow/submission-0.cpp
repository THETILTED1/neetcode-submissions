array<pair<int, int>, 4> dir = {{
    {1, 0},
    {0, 1},
    {-1, 0},
    {0, -1}
}};

class Solution {
public:
    bool bounds(vector<vector<int>>& g, pair<int, int> c){
        return (c.first >= 0) and (c.first < g.size())
            and (c.second >= 0) and (c.second < g[0].size());
    }

    void trynq(vector<vector<int>>& g, const pair<int, int>& c,
        queue<pair<int, int>>& q, unordered_set<int>& ss){

        for (const auto& d : dir){
            pair<int, int> a = 
            {c.first + d.first, c.second + d.second};

            if (!bounds(g, a)) continue;

            int af = a.first * g[0].size() + a.second;
            if (ss.contains(af)) continue;

            if (g[a.first][a.second] >= g[c.first][c.second]){
                ss.insert(af);
                q.push(a);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        queue<pair<int, int>> q;
        int m = heights.size();
        int n = heights[0].size();

        unordered_set<int> ss{};

        for (int i = 0; i < m; i++){
            q.push({i, 0});
            ss.insert(n * i);
        }
        
        for (int i = 1; i < n; i++){
            q.push({0, i});
            ss.insert(i);
        }

        while (!q.empty()){
            pair<int, int> k = q.front();
            q.pop();
            trynq(heights, k, q, ss);
        }

        vector<vector<int>> res{};
        unordered_set<int> ts{};

        for (int i = 0; i < m; i++){
            q.push({i, n - 1});
            ts.insert(n * i + n - 1);
        }
        
        for (int i = 0; i < n - 1; i++){
            q.push({m - 1, i});
            ts.insert(i + n * (m - 1));
        }

        while (!q.empty()){
            pair<int, int> k = q.front();
            q.pop();
            trynq(heights, k, q, ts);

            if (ss.contains(k.first * n + k.second)){
                res.push_back({k.first, k.second});
            }
        }        

        return res;
    }
};
