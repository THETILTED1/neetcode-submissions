class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        vector<int> res(queries.size());
        vector<pair<int, int>> sq{};
        for (int i = 0; i < queries.size(); i++)
            sq.emplace_back(queries[i], i);
        sort(sq.begin(), sq.end());

        priority_queue<pair<int, int>, vector<pair<int, int>>,
            greater<pair<int, int>>> pq{};

        unordered_map<int, int> discard{};
        priority_queue<int, vector<int>, greater<int>> lens{};
        
        for (auto& v : intervals){
            int l = v[1] - v[0] + 1;
            pq.emplace(v[0], -l);
            pq.emplace(v[1], l);
        }

        for (auto& r : sq){
            while (!pq.empty() and pq.top().first < r.first){
                auto ss = pq.top();
                pq.pop();
                if (ss.second < 0)
                    lens.push(-ss.second);
                else 
                    discard[ss.second]++;
            }

            while (!pq.empty() and pq.top().first == r.first
                and pq.top().second < 0){
                    
                auto ss = pq.top();
                pq.pop();
                lens.push(-ss.second);
            }

            while (!lens.empty() and discard[lens.top()] > 0){
                int e = lens.top();
                discard[e]--;
                lens.pop();
            }

            res[r.second] = lens.empty() ? -1 : lens.top();
        }

        return res;
    }
};
