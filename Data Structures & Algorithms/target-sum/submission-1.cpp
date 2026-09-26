class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        unordered_map<int, int> dp{};
        dp[0] = 1;
        for (int n : nums){
            unordered_map<int, int> tmp{};
            for (const auto& pp : dp){
                tmp[pp.first + n] += pp.second;
                tmp[pp.first - n] += pp.second;
            }
            dp = move(tmp);
        }
        return dp[target];
    }
};
