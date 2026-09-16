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
        if (intervals.empty()) 
            return true;

        sort(intervals.begin(), intervals.end(), 
            [](const Interval& a, const Interval& b){ 
                return a.start < b.start; });
        
        for (int r = 1; r < intervals.size(); r++)
            if (intervals[r - 1].end > intervals[r].start)
                return false;
        
        return true;  
    }
};
