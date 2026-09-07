class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int r = 0;
        int s = 0;
        for (int i = 0; i < nums.size(); i++){
            r ^= i;
            s ^= nums[i];
        }
        r ^= nums.size();
        return r ^ s;
    }
};
