class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int g = accumulate(gas.begin(), gas.end(), 0);
        int c = accumulate(cost.begin(), cost.end(), 0);
        if (g < c)
            return -1;

        int res = 0;
        int t = 0;
        for (int i = 0; i < n; i++){
            t += gas[i] - cost[i];
            if (t < 0){
                t = 0;
                res = i + 1;
            }
        }

        return res;
    }
};
