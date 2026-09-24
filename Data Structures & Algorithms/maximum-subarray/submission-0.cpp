class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int best = nums[0], m = nums[0];
        for (int i = 1; i < nums.size(); i++){
            m = max(m + nums[i], nums[i]);
            best = max(best, m);
        }
        return best;
    }
};
