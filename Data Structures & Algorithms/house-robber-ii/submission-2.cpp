class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1)
            return nums[0];
        
        int x = 0, y = 0, z = 0, w = 0, tmp;
        for (int i = 0; i < nums.size() - 1; i++){
            tmp = x;
            x = max(x, y + nums[i]);
            y = tmp;
            tmp = z;
            z = max(z, w + nums[i + 1]);
            w = tmp;
        }
        return max(x, z);        
    }
};
