class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();

        int g = 0;
        int t = 0;
        int res = 0;
        for (int i = 0; i < n; i++){
            int di = gas[i] - cost[i];
            t += di;
            g += di;
            if (t < 0){
                t = 0;
                res = i + 1;
            }
        }
        if (g < 0)
            return -1;
        return res;
    }
};
