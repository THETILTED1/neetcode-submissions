class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int lo = nums[0];
        int hi = nums[0];
        int res = nums[0];
        
        for (int r = 1; r < nums.size(); r++) {
            int temp_hi = hi;
            
            hi = max({nums[r], temp_hi * nums[r], lo * nums[r]});
            lo = min({nums[r], temp_hi * nums[r], lo * nums[r]});
            
            res = max(res, hi);
        }
        
        return res;
    }
};