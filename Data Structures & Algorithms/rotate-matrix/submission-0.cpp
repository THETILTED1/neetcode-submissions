class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        for (auto& v : matrix)
            reverse(v.begin(), v.end());
        
        int n = matrix.size();

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n - i; j++)
                swap(matrix[i][j], matrix[n-j-1][n-i-1]);
            
    }
};
