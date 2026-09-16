/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        if (intervals.size() == 0) return true;
        map<int, int> times{};
        times[intervals[0].start] = intervals[0].end;
        for (int r = 1; r < intervals.size(); r++){
            auto lub = times.lower_bound(intervals[r].start);
            if (lub != times.end() and lub->first < intervals[r].end)
                return false;
            if (lub != times.begin() and 
                intervals[r].start < prev(lub)->second)
                return false; 

            times[intervals[r].start] = intervals[r].end;           
        }
        return true;
    }
};
