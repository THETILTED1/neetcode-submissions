class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() == 1) 
            return 0;

        int k = 1;
        int upper = nums[0];
        int it = 0;

        for (int i = 1; i < nums.size() and upper < nums.size() - 1; i++){
            it = max(it, i + nums[i]);
            if (i == upper){
                upper = it;
                k++;
            }
        }

        return k;
    }
};
