#include <unordered_map>

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> dict{};
        for (int i = 0; i < nums.size(); i++){
            if (dict.contains(nums[i])){
                std::vector<int> result = {dict[nums[i]], i};
                return result;
            }

            dict.insert({target - nums[i], i});
        }

        return {};
    }
};
