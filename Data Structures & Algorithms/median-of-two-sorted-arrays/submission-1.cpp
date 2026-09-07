class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        int n1 = nums1.size();
        int n2 = nums2.size();

        vector<int>& vec1 = (n1 >= n2) ? nums1 : nums2; //big
        vector<int>& vec2 = (n1 < n2) ? nums1 : nums2; //small

        int half = (n1 + n2 + 1) / 2;
        bool odd = (n1 ^ n2) & 1;

        int r = (n1 + n2 - 1) / 2;
        int l = r - vec2.size();

        int em;

        while (l < r){
            int mid = l + (r - l + 1) / 2;

            int vv = min((int)vec2.size() - 1, half - mid - 1);

            if (vec1[mid] < vec2[vv]){ 
                l = mid; 
            }
            else { r = mid - 1; }
        }

        int ct = half - (l + 1);
        
        // 1. Guard L1
        int l1 = (l >= 0) ? vec1[l] : INT_MIN;
        
        // (Your R1 was already perfect!)
        int r1 = (l + 1 < vec1.size()) ? vec1[l + 1] : INT_MAX;
        
        // 2 & 3. Fix the index and guard L2 and R2
        int l2 = (ct - 1 >= 0) ? vec2[ct - 1] : INT_MIN;
        int r2 = (ct < vec2.size()) ? vec2[ct] : INT_MAX;
  
        if (odd){
            return max(l1, l2);
        }
        
        // 4. Use r1 and r2 for the right half!
        return (max(l1, l2) + min(r1, r2)) / 2.0;
    }
};
