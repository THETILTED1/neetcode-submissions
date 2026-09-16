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
    int minMeetingRooms(vector<Interval>& intervals) {
        vector<int> starts{};
        vector<int> ends{};
        for (auto& i : intervals){
            starts.push_back(i.start);
            ends.push_back(i.end);
        }
        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());

        int s = 0, e = 0;
        int cts = 0, m = 0;

        while (s < intervals.size()){
            if (starts[s] < ends[e]){
                cts++;
                m = max(m, cts);
                s++;
            } else {
                cts--;
                e++;
            }
        }

        return m;
    }
};
