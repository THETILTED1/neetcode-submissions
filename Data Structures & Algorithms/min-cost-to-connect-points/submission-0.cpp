class DSU{
public:
    vector<int> parent{};
    vector<int> size{};
    int cmp;

    DSU(int n){
        size.assign(n, 1);
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
        cmp = n;
    }

    int find(int u){
        if (parent[u] == u)
            return u;
        return parent[u] = find(parent[u]);
    }

    bool join(int u, int v){
        int pu = find(u);
        int pv = find(v);

        if (pu == pv)
            return false;

        if (size[pu] < size[pv])
            swap(pu, pv);
        parent[pv] = pu;
        size[pu] += size[pv];
        cmp--;
        return true;
    }
};

class Solution {
public:
    int dist(const vector<int>& a, const vector<int>& b){
        return abs(a[0] - b[0]) + abs(a[1] - b[1]);
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<pair<int, pair<int, int>>> edges{};
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < points.size(); j++)
                edges.push_back({dist(points[i], points[j]), {i, j}});
        
        sort(edges.begin(), edges.end());
        
        DSU dsu(n);
        int cost = 0;
        for (int i = 0; i < edges.size() and dsu.cmp > 1; i++){
            auto [w, e] = edges[i];
            if (dsu.join(e.first, e.second))
                cost += w;
        }
        return cost;
    }
};
