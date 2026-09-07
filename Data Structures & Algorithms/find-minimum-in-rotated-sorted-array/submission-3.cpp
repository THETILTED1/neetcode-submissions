class Solution {
public:
    int findMin(vector<int> &nums) {
        int n = nums.size();

        int l = 0, r = n - 1;
        int mid;

        while (l < r){
            mid = l + (r - l) / 2;
            if (nums[mid] > nums[n - 1]){ l = mid + 1; }
            if (nums[mid] <= nums[n - 1]){ r = mid; }
        }

        return nums[r];
    }
};
