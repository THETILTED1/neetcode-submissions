class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> in(numCourses, 0);

        for (auto& e : prerequisites){
            adj[e[1]].push_back(e[0]);
            in[e[0]]++;
        }
        
        queue<int> q{};

        for (int i = 0; i < numCourses; i++)
            if (in[i] == 0)
                q.push(i);
            
        int clear = 0;

        while (!q.empty()){
            int u = q.front();
            q.pop();
            clear++;

            for (auto& i : adj[u]){
                in[i]--;
                if (in[i] == 0)
                    q.push(i);
            }       
        }

        return clear == numCourses;
    }
};
