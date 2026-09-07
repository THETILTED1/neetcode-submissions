#include <unordered_set>

class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_set<int> seen{};
        for (int k : nums){
            if (seen.contains(k)){
                return true;
            }
            seen.insert(k);
        }
        return false;
    }
};