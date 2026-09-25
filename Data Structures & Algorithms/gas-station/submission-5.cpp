class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();

        int worst = 0;
        int m = 0;
        int si = -1;
        for (int i = 0; i < 2 * n; i++){
            int k = i % n;
            int di = gas[k] - cost[k];
            m = min(di, m + di);
            if (m < worst){
                worst = m;
                si = i;
            }
        }

        int l = (si + 1) % n;
        int s = 0;
        for (int i = 0; i < n; i++){
            int k = (i + l) % n;
            s += gas[k] - cost[k];
            if (s < 0)
                return -1;
        }

        return l;
    }
};
