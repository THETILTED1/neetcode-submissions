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

        int find(int v){
            if (parent[v] == v){
                return v;
            }
            return parent[v] = find(parent[v]);
        }

        void join(int u, int v){
            int pu = find(u);
            int pv = find(v);

            if (pu == pv) return;

            if (size[pu] < size[pv]){
                swap(pu, pv);
            }
            parent[pv] = pu;
            size[pu] += size[pv];
            cmp--;
        }

};

class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        DSU dsu(n);
        for (auto v : edges){
            dsu.join(v[0], v[1]);
        }
        return dsu.cmp;
    }
};
