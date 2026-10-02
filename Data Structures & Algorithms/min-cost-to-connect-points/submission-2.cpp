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

        priority_queue<pair<int, int>, vector<pair<int, int>>, 
            greater<pair<int, int>>> pq{};

        for (int i = 1; i < n; i++)
            pq.emplace(dist(points[0], points[i]), i);

        while (cts < n and !pq.empty()){
            auto [w, e] = pq.top();
            pq.pop();
            
            if (seen[e])
                continue;
            
            cost += w;
            cts++;
            seen[e] = true;
            for (int i = 0; i < n; i++)
                if (!seen[i])
                    pq.emplace(dist(points[e], points[i]), i);
        }
        
        return cost;
    }
};
