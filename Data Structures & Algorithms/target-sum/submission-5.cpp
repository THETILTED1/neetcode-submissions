class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (abs(target) > sum)
            return 0;
        if ((sum + target) & 1)
            return 0;

        int amount = (target + sum) / 2;
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;
        for (int n : nums)
            for (int j = amount - n; j >= 0; j--)
                dp[j + n] += dp[j];
        
        return dp[amount];        
    }
};
