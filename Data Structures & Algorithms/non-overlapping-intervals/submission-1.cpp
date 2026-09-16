class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int prev = intervals[0][1];
        int cts = 0;
        for (int r = 1; r < intervals.size(); r++){
            if (intervals[r][0] >= prev){
                prev = intervals[r][1];
            } else {
                prev = min(prev, intervals[r][1]);
                cts++;
            }
        }

        return cts;        
    }
};
