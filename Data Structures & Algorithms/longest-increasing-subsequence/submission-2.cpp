class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> lims{};
        for (int i = 0; i < n; i++){
            auto it = lower_bound(lims.begin(), lims.end(), nums[i]);
            if (it != lims.end())
                *it = nums[i];
            else
                lims.push_back(nums[i]);
        }
        return lims.size();
        
    }
};
