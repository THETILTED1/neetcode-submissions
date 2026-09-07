class Solution {
public:
    vector<vector<int>> res{};
    vector<int> path{};
    int sum = 0;

    void dfs(const vector<int>& nums, int l, int target){
        if (sum > target){ return; }
        if (sum == target){ res.push_back(path); }

        for (int i = l; i < nums.size(); i++){
            sum += nums[i];
            path.push_back(nums[i]);

            dfs(nums, i, target);

            path.pop_back();
            sum -= nums[i];
        }
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        
        sort(nums.begin(), nums.end(), greater<int>());
        
        dfs(nums, 0, target);

        return res;     
    }
};
