class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int start = n - 1, end  = 0;
        int t = gas[start] - cost[start];
        while (start > end){
            if (t < 0){
                start--;
                t += gas[start] - cost[start];
            } else {
                t += gas[end] - cost[end];
                end++;
            }
        }
        if (t >= 0)
            return start;
        return -1;
    }
};
