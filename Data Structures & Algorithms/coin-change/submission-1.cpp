class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        for (int i = 0; i < coins.size(); i++){
            for (int j = 0; j <= amount - coins[i]; j++){
                dp[j + coins[i]] = min(dp[j + coins[i]], dp[j] + 1);
            }
        }
        return dp[amount] > amount ? -1 : dp[amount];
    }
};
