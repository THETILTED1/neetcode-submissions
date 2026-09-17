class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int x = cost[1], y = cost[0];
        cost.push_back(0);
        for (int i = 2; i < cost.size(); i++){
            int tmp = x;
            x = cost[i] + min(x, y);
            y = tmp;
        }
        return x;
    }
};
