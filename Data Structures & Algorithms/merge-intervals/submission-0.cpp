class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(),
            [](vector<int>& a, vector<int>& b){ return a[0] < b[0]; });

        vector<int> cc = intervals[0];
        vector<vector<int>> res{};

        for (int i = 1; i < intervals.size(); i++){
            if (intervals[i][0] > cc[1]){
                res.push_back(cc);
                cc = intervals[i];
            } else {
                cc[1] = max(intervals[i][1], cc[1]);
            }
        }

        res.push_back(cc);

        return res;
    }
};
