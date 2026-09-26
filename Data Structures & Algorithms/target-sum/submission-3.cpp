class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> part(n + 1, 0);
        partial_sum(nums.begin(), nums.end(), part.begin() + 1);
        int sum = part.back();

        if (abs(target) > sum)
            return 0;

        vector<vector<int>> dp(n + 1, vector<int>(2 * sum + 1, 0));
        dp[0][0 + sum] = 1;
        for (int i = 0; i < n; i++)
            for (int j = -part[i]; j <= part[i]; j++){
                dp[i + 1][j + sum + nums[i]] += dp[i][j + sum];
                dp[i + 1][j + sum - nums[i]] += dp[i][j + sum];
            }
        
        return dp[n][target + sum];
    }
};
