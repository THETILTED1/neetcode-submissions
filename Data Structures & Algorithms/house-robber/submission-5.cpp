class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() < 2)
            return nums[0];
        int y = nums[0], x = max(y, nums[1]);
        for (int i = 2; i < nums.size(); i++){
            int tmp = x;
            x = max(x, y + nums[i]);
            y = tmp;
        }
        return max(x, y);
    }
};
