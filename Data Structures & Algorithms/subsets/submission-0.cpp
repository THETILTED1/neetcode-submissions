class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res{};
        
        vector<int> st{};
        int sz = 1 << nums.size();

        for (uint32_t j = 0; j < sz; j++){
            uint32_t i = j;
            while (i){
                uint32_t k = countr_zero<uint32_t>(i);
                i &= (i - 1);
                st.push_back(nums[k]);
            }
            res.push_back(st);
            st.clear();
        }

        return res;
    }
};
