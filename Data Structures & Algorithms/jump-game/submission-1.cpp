class Solution {
public:
    bool canJump(vector<int>& nums) {
        int upper = 0;
        for (int i = 0; i < nums.size() and i <= upper; i++)
            if ((upper = max(upper, i + nums[i])) >= nums.size() - 1)
                return true;
        
        return false;
    }
};
