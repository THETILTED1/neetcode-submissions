using Edge = pair<int, pair<int, int>>;

class Solution {
public:
    int dist(const vector<int>& a, const vector<int>& b){
        return abs(a[0] - b[0]) + abs(a[1] - b[1]);
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<bool> seen(n, false);
        seen[0] = true;
        int cts = 1;
        int cost = 0;

        priority_queue<Edge, vector<Edge>, greater<Edge>> pq{};
        for (int i = 1; i < n; i++)
            pq.push({dist(points[0], points[i]), {0, i}});

        while (cts < n and !pq.empty()){
            auto [w, e] = pq.top();
            pq.pop();
            
            if (seen[e.second])
                continue;
            
            cost += w;
            cts++;
            seen[e.second] = true;
            for (int i = 0; i < n; i++)
                if (!seen[i])
                    pq.push({dist(points[e.second], points[i]), 
                        {e.second, i}});
        }
        
        return cost;
    }
};
