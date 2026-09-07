class Solution {
public:
    int get(vector<vector<int>>& m, int i){
        int n = m[0].size();
        int j = i / n;
        int k = i % n;
        return m[j][k];
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        int l = 0;
        int r = m * n - 1;

        while (l <= r){
            int mid = (l + r) / 2;
            if (get(matrix, mid) == target){ return true; }
            if (get(matrix, mid) > target){ r = mid - 1; }
            if (get(matrix, mid) < target){ l = mid + 1; } 
        }

        return false;        
    }
};
