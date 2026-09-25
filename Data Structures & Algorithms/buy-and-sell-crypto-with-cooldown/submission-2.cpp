class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 1)
            return 0;
        if (n == 2)
            return max(0, prices[1] - prices[0]);

        //vector<pair<int, int>> dp(n);
        array<pair<int, int>, 2> dp{};

        dp[0] = {0, -prices[0]};
        dp[1] = {max(prices[1] - prices[0], 0), max(-prices[0], -prices[1])};

        for (int i = 2; i < n; i++){
            auto tmp = dp[1];
            dp[1].first = max(dp[1].first, dp[1].second + prices[i]);
            dp[1].second = max(dp[1].second, dp[0].first - prices[i]);
            dp[0] = tmp;
        }

        return dp[1].first;
    }
};
