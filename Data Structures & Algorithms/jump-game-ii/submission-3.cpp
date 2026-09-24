class Solution {
public:
    int jump(vector<int>& nums) {
        int k = 0;
        int upper = 0;
        int it = 0;
        for (int i = 0; i < nums.size() - 1 and upper < nums.size() - 1; i++){
            it = max(it, i + nums[i]);
            if (i == upper){
                upper = it;
                k++;
            }
        }

        return k;
    }
};
