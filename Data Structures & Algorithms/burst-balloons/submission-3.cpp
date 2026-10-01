class Solution {
public:
    int dfs(vector<int>& nums, int l, int r, vector<vector<int>>& mem){
        if (mem[l][r])
            return mem[l][r];
        if (l > r)
            return 0;
        
        int res = 0;
        for (int k = l; k <= r; k++){
            int left = dfs(nums, l, k - 1, mem);
            int right = dfs(nums, k + 1, r, mem);
            int burst = nums[l - 1] * nums[k] * nums[r + 1];
            res = max(res, left + right + burst);
        }        

        mem[l][r] = res;
        return res;
    }
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        
        vector<vector<int>> mem(n + 2, vector<int>(n + 2, 0));
        return dfs(nums, 1, n, mem);
    }
};
