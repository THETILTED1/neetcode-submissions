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
        int mt = 0;
        for (auto& i : intervals)
            mt = max(mt, i.end);
        
        vector<int> sim(mt + 1, 0);
        for (auto& i : intervals){
            sim[i.start]++;
            sim[i.end]--;
        }

        int cts = 0, m = 0;
        for (int j = 0; j < mt; j++){
            cts += sim[j];
            m = max(m, cts);
        }
        return m;
    }
};
