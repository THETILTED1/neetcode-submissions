class Solution {
public:
    int euclid(vector<int>& p){
        return p[0] * p[0] + p[1] * p[1];
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        priority_queue<pair<int, int>> pq{};
        int v;
        for (int i = 0; i < points.size(); i++){
            v = euclid(points[i]);
            if (pq.size() < k){
                pq.push({v, i});
                continue;
            }

            if (v < pq.top().first){
                pq.push({v, i});
                pq.pop();
            }
        }
        vector<vector<int>> res{};
        while (!pq.empty()){
            res.push_back(points[pq.top().second]);
            pq.pop();
        }

        return res;        
    }
};
