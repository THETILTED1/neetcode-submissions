class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

        for (int len = 1; len <= n; len++){
            for (int l = 1; l <= n - len + 1; l++){
                int r = l + len - 1;
                for (int k = l; k <= r; k++){
                    int left = dp[l][k - 1];
                    int right = dp[k + 1][r];
                    int burst = nums[l - 1] * nums[k] * nums[r + 1];
                    dp[l][r] = max(dp[l][r], left + right + burst);
                }
            }
        }

        return dp[1][n];
    }
};
