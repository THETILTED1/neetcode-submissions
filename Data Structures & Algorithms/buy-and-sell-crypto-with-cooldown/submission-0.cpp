class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 1)
            return 0;
        if (n == 2)
            return max(0, prices[1] - prices[0]);

        vector<pair<int, int>> dp(n);

        // best PnL to have X inventory at time i
        // dp[0] = 0, -p[0]
        // dp[1] = max(p[1] - p[0]), max(-p[0], -p[1])
        // dp[2] = 

        dp[0] = {0, -prices[0]};
        dp[1] = {max(prices[1] - prices[0], 0), max(-prices[0], -prices[1])};

        for (int i = 2; i < n; i++){
            dp[i].first = max(dp[i - 1].first, dp[i - 1].second + prices[i]);
            dp[i].second = max(dp[i - 1].second, dp[i - 2].first - prices[i]);
        }

        return dp[n - 1].first;
    }
};
