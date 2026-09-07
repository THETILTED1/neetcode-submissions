class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        int len = nums.size();
        int i = 1;
        while (i < len){
            int key = nums[i];
            int j = i;
            while (j > 0 and nums[j - 1] > key){
                nums[j] = nums[j - 1];
                j = j - 1;
            }
            nums[j] = key;
            i++;
        }

        for (int k = 1; k < len; k++){
            if (nums[k] == nums[k - 1]){
                return true;
            }
        }
    
        return false;
    }
};