class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        
        int l = 0, r = n - 1;
        int mid;

        while (l < r){
            mid = l + (r - l) / 2;
            if (nums[mid] > nums[n - 1]){ l = mid + 1; }
            if (nums[mid] <= nums[n - 1]){ r = mid; }
        }

        int k = r;
        l = k;
        r = k + n - 1;

        while (l < r){
            mid = l + (r - l) / 2;
            if (nums[mid % n] >= target){ r = mid; }
            else { l = mid + 1; }
        }
        
        if (nums[r % n] == target){ return r % n; }
        return -1;
    }
};
