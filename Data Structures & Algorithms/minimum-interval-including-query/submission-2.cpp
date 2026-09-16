class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        vector<int> res(queries.size(), -1);
        vector<pair<int, int>> sq{};
        for (int i = 0; i < queries.size(); i++)
            sq.emplace_back(queries[i], i);
        sort(sq.begin(), sq.end());

        sort(intervals.begin(), intervals.end());

        priority_queue<pair<int, int>, vector<pair<int, int>>,
            greater<pair<int, int>>> pq{};

        int i = 0, n = intervals.size();

        for (auto& r : sq){
            while (i < n and intervals[i][0] <= r.first){
                int l = intervals[i][1] - intervals[i][0] + 1;
                pq.emplace(l, intervals[i][1]);
                i++;
            }

            while (!pq.empty() and pq.top().second < r.first)
                pq.pop();

            if (!pq.empty())
                res[r.second] = pq.top().first;
        }

        return res;
    }
};
