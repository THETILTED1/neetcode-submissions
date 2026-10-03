class Solution {
public:
    vector<vector<pair<int, int>>> adj{};
    vector<vector<pair<bool, int>>> mem{};

    int dfs(int u, int dst, int k, int len){
        if (u == dst)
            return 0;
        if (len > k)
            return INT_MAX;
        if (mem[u][len].first)
            return mem[u][len].second;

        int best = INT_MAX;
        for (auto [v, w] : adj[u]){
            int r = dfs(v, dst, k, len + 1);
            r = r == INT_MAX ? INT_MAX : r + w;

            best = min(best, r);
        }

        mem[u][len] = {true, best};

        return best;
    }

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        adj.resize(n);
        
        for (const auto& e : flights)
            adj[e[0]].emplace_back(e[1], e[2]);
        
        mem.resize(n);
        for (auto& vec : mem)
            vec.assign(k + 1, {false, INT_MAX});

        int res = dfs(src, dst, k, 0);
        return res == INT_MAX ? -1 : res;       
    }
};
