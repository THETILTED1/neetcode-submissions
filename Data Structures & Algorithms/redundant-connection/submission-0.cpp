class Solution {
public:
    unordered_map<int, vector<int>> adj{};
    unordered_set<int> seen{};
    unordered_set<int> cycle{};
    int halt = -1;

    bool dfs(int l, int p){
        if (seen.contains(l)){
            halt = l;
            return true;
        }

        seen.insert(l);
        for (auto v : adj[l]){
            if (v == p) continue;

            if (dfs(v, l)){
                if (halt != -1){
                    cycle.insert(l);
                    if (l == halt)
                        halt = -1;
                }

                return true;
            }
        }

        return false;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        for (const auto& e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        dfs(edges[0][0], -1);
        for (int i = edges.size() - 1; i >= 0; i--){
            if (cycle.contains(edges[i][0]) and cycle.contains(edges[i][1])){
                return edges[i];
            }
        }



        
    }
};
