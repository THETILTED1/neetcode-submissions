class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minp = 101;
        int best = 0;
        int sz = prices.size();
        for (int i = 0; i < sz; i++){
            int d = prices[i] - minp;
            best = max(d, best);
            minp = min(minp, prices[i]);
        }

        return best;
    }
};
