class Solution {
public:
    bool dfscycle(vector<int>& states, vector<vector<int>>& adj, int u){
        if (states[u] == 1) return true;
        if (states[u] == 2) return false;

        states[u]++;

        for (int v : adj[u]){
            if (dfscycle(states, adj, v))
                return true;
        }

        states[u]++;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> states(numCourses, 0);
        vector<vector<int>> adj(numCourses);
        for (auto& e : prerequisites)
            adj[e[1]].push_back(e[0]);

        for (int i = 0; i < numCourses; i++)
            if (dfscycle(states, adj, i))
                return false;
    
        return true;
    }
};
