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
        priority_queue<pair<int, int>, vector<pair<int, int>>, 
            greater<pair<int, int>>> pq{};

        for (auto& i : intervals){
            pq.emplace(i.start, 1);
            pq.emplace(i.end, -1);
        }

        int cts = 0;
        int m = 0;
        while (!pq.empty()){
            auto pp = pq.top();
            pq.pop();
            cts += pp.second;
            m = max(m, cts);
        }
        return m;
    }
};
