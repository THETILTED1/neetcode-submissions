class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> lims(n + 1, {INT_MAX, -INT_MAX});
        lims[1].first = nums[0];
        int l = 1;

        for (int i = 1; i < n; i++){
            for (int j = 1; j <= l; j++){
                auto& ll = lims[j];
                if (nums[i] > ll.second)
                    ll.first = min(nums[i], ll.first);

                if (nums[i] > lims[j-1].first and nums[i] < ll.first){
                    ll.first = nums[i];
                    ll.second = lims[j - 1].first;
                }
            }
            if (nums[i] > lims[l].first){
                lims[l + 1].first = nums[i];
                lims[l + 1].second = lims[l].first;
                l++;
            }
        }

        return l;
    }
};