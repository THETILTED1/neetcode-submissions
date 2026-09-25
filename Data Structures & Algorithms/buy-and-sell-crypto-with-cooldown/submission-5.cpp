class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        array<pair<int, int>, 2> dp{};

        dp[0] = {0, 0};
        dp[1] = {0, INT_MIN};

        for (int p : prices){
            auto tmp = dp[1];
            dp[1].first = max(dp[1].first, dp[1].second + p);
            dp[1].second = max(dp[1].second, dp[0].first - p);
            dp[0] = tmp;
        }

        return dp[1].first;
    }
};
