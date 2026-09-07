class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res{};
        stack<pair<int, int>> st{};

        vector<int> path{};
        vector<int> idxs{};
        vector<bool> seen(nums.size(), false);

        for (int i = 0; i < nums.size(); i++){
            st.emplace(i, 0);
        }
        
        while (!st.empty()){
            pair<int, int> pp = st.top();
            st.pop();

            while (path.size() > pp.second){
                seen[idxs[path.size() - 1]] = false;
                idxs.pop_back();
                path.pop_back();
            }

            path.push_back(nums[pp.first]);
            idxs.push_back(pp.first);
            seen[pp.first] = true;

            if (path.size() == nums.size()){
                res.push_back(path);
                continue;
            }

            for (int i = 0; i < nums.size(); i++){
                if (!seen[i]){
                    st.emplace(i, pp.second + 1);
                }
            }
        }

        return res;
    }
};
