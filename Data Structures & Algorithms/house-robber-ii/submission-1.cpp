class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) 
            return nums[0];

        int x = 0, y = 0;
        for (int i = 0; i < nums.size() - 1; i++){
            int tmp = x;
            x = max(x, y + nums[i]);
            y = tmp;
        }
        int res = x;
        x = y = 0;
        for (int i = 1; i < nums.size(); i++){
            int tmp = x;
            x = max(x, y + nums[i]);
            y = tmp;
        }
        return max(res, x);
    }
};
