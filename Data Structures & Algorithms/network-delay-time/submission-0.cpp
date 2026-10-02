class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int longest = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>,
            greater<pair<int, int>>> pq{};

        vector<int> dist(n + 1, INT_MAX);
        vector<bool> seen(n + 1, false);
        int cts = 0;

        vector<vector<pair<int, int>>> adj(n + 1);
        for (auto& e : times)
            adj[e[0]].emplace_back(e[2], e[1]);
        
        pq.emplace(0, k);
        while (!pq.empty()){
            auto [d, u] = pq.top();
            pq.pop();

            if (d >= dist[u])
                continue;
            
            cts += !seen[u];
            seen[u] = true;
            
            dist[u] = d;
            longest = max(longest, d);
            for (const auto& [w, v] : adj[u])
                pq.emplace(d + w, v);
        }
        
        return cts == n ? longest : -1;
    }
};
