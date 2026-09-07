class DSU{
    public:
    vector<int> parent{};
    vector<int> size{};
    int cmp;

    DSU(int n){
        parent.resize(n);
        size.assign(n, 1);

        for (int i = 0; i < n; i++){
            parent[i] = i;
        }
        cmp = n;
    }

    bool join(int u, int v){
        int pu = find(u);
        int pv = find(v);

        if (pu == pv) return false;

        if (size[pu] < size[pv])
            swap(pu, pv);

        size[pu] += size[pv];
        parent[pv] = parent[pu];
        cmp--;

        return true;        
    }

    int find(int v){
        if (parent[v] == v)
            return v;
        return parent[v] = find(parent[v]);
    }
};

class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n - 1) return false;

        DSU dsu(n);
        for (const auto& e : edges){
            if (!dsu.join(e[0], e[1]))
                return false;
        }

        return true;
    }
};
