class DSU{
public:
    vector<int> size{};
    vector<int> parent{};
    int n;

    DSU(int m){
        n = m;
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
        size.assign(n, 1);
    }

    int find(int u){
        if (u == parent[u])
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
        return true;
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int m = 0;
        for (auto& e : edges)
            m = max(m, max(e[0], e[1]));
        
        DSU dsu(m + 1);
        for (auto& e : edges)
            if (!dsu.join(e[0], e[1]))
                return e;

        return {};
    }
};
