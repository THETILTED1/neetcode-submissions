class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum & 1)
            return 0;
        
        bitset<2501> dp{};
        dp[0] = 1;
        for (int n : nums)
            dp |= (dp << n);
        
        return dp[sum >> 1];
    }
};
