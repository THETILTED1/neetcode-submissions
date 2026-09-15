class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res{};

        bool in = false;

        for (auto& v : intervals){
            int tf = max(newInterval[1], v[1]);
            int ti = min(newInterval[0], v[0]);
            int la = newInterval[1] - newInterval[0];
            int lb = v[1] - v[0];

            if (tf - ti <= la + lb){
                newInterval[0] = ti;
                newInterval[1] = tf;
            } else if (v[1] < newInterval[0] and !in){
                res.push_back(v);
            } else if (newInterval[1] < v[0] and !in){
                res.push_back(newInterval);
                res.push_back(v);
                in = true;
            } else {
                res.push_back(v);
            }
        }
        if (!in)
            res.push_back(newInterval);

        return res;
    }
};
