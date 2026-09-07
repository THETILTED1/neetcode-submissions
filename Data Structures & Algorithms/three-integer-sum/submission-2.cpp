class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        int li = -1;
        for (int i = 0; i < nums.size(); i++){
            int a = i + 1, b = nums.size() - 1;
            if (li > -1 and nums[i] == nums[li]){ continue; }
            while (a < b){
                int sum = nums[i] + nums[a] + nums[b];
                if (sum == 0){
                    result.push_back({nums[i], nums[a], nums[b]});
                    int xa = nums[a], xb = nums[b];
                    li = i;
                    while (nums[a] == xa and a < b){ a++; }
                    while (nums[b] == xb and a < b){ b--; }
                } else if (sum < 0){
                    a++;
                } else { 
                    b--;
                }
            }
        }
        return result;
    }
};
