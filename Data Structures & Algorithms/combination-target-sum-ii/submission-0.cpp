class Solution {
public:
    vector<vector<int>> res{};
    vector<int> path{};
    int sum = 0;

    void dfs(vector<int>& candidates, int l, int target){
        if (sum > target){ return; }
        if (sum == target){ 
            res.push_back(path); 
            return;
        }

        int curr = 0;

        for (int i = l + 1; i < candidates.size(); i++){
            if (candidates[i] == curr){
                continue;
            }
            curr = candidates[i];

            sum += candidates[i];
            path.push_back(candidates[i]);

            dfs(candidates, i, target);

            path.pop_back();
            sum -= candidates[i];
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        dfs(candidates, -1, target);
        return res;
    }
};
