class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        if (nums.size() == 1){
            return nums;
        }
        vector<int> lower = nums;
        vector<int> upper = nums;

        for (int i = 1; i < nums.size(); i++){
            lower[i] = lower[i] * lower[i - 1];
            upper[nums.size() - i - 1] = upper[nums.size() - i] * upper[nums.size() - i - 1];
        }

        vector<int> result{};
        result.push_back(upper[1]);
        for (int i = 1; i < nums.size() - 1; i++){
            result.push_back(lower[i - 1] * upper[i + 1]);
        }
        result.push_back(lower[nums.size() - 2]);

        return result;
    }
};
