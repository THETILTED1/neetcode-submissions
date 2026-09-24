class Solution {
public:
    bool canJump(vector<int>& nums) {
        int upper = 0;
        for (int i = 0; i < nums.size() and i <= upper; i++){
            upper = max(upper, i + nums[i]);
        }
        return upper >= nums.size() - 1;
    }
};
