class Solution {
public:
    void build(vector<vector<int>>& g, int n, int k){
        int a = g.size();
        for (int i = 0; i < a; i++){
            vector<int> next = g[i];
            for (int i = 1; i <= k; i++){
                next.push_back(n);
                g.push_back(next);
            }
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> res{};
        vector<int> ks{};
        vector<int> ds{};
        int b = nums[0];
        int c = 1;
        for (int i = 1; i < nums.size(); i++){
            if (nums[i] == b){
                c++;
            } else {
                ks.push_back(c);
                ds.push_back(b);
                b = nums[i];
                c = 1;
            }
        }
        ds.push_back(b);
        ks.push_back(c);
    
        res.push_back({});

        for (int i = 0; i < ds.size(); i++){
            build(res, ds[i], ks[i]);
        }
        
        return res;
    }
};
