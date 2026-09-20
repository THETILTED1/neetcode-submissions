class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int n : nums)
            sum += n;

        if (sum & 1)
            return false;
        
        unordered_set<int> dp{};
        dp.insert(sum / 2);
        for (int i = 0; i < nums.size(); i++){
            unordered_set<int> tmp{};
            for (const auto& j : dp)
                if (j >= nums[i]){
                    if (j == nums[i])
                        return true;
                    tmp.insert(j - nums[i]);
                }
            dp.merge(tmp);                
        }

        return false;
    }
};
