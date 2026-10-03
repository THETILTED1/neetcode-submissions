class Solution {
public:
    vector<vector<pair<int, int>>> adj{};
    vector<vector<pair<bool, int>>> mem{};
    vector<bool> seen{};

    int dfs(int u, int dst, int k, int len, int cost){
        if (u == dst)
            return cost;
        if (len > k)
            return INT_MAX;
        if (mem[u][len].first)
            return mem[u][len].second;

        seen[u] = true;

        int best = INT_MAX;
        for (auto [v, w] : adj[u]){
            if (seen[v])
                continue;
            best = min(best, dfs(v, dst, k, len + 1, cost + w));
        }

        seen[u] = false;
        mem[u][len] = {true, best};

        return best;
    }

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

        sort(flights.begin(), flights.end(), 
            [](const vector<int>& a, const vector<int>& b){
                return a[2] < b[2]; });
        
        adj.resize(n);
        
        for (const auto& e : flights)
            adj[e[0]].emplace_back(e[1], e[2]);
        
        seen.assign(n, false);
        mem.resize(n);
        for (auto& vec : mem)
            vec.assign(k + 1, {false, INT_MAX});

        int res = dfs(src, dst, k, 0, 0);
        return res == INT_MAX ? -1 : res;       
    }
};
