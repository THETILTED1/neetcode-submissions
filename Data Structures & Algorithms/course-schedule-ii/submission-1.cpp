class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> res{};
        vector<vector<int>> adj(numCourses);
        vector<int> in(numCourses, 0);

        int l = 0, r;

        for (auto& e : prerequisites){
            adj[e[1]].push_back(e[0]);
            in[e[0]]++;
        }

        for (int i = 0; i < numCourses; i++)
            if (in[i] == 0)
                res.push_back(i);
        
        r = res.size();

        while (l < r){
            int u = res[l];
            l++;

            for (int& v : adj[u]){
                in[v]--;
                if (in[v] == 0){
                    res.push_back(v);
                    r++;
                }
            }
        }
            
        if (r != numCourses) 
            return {};    

        return res;
    }
};
