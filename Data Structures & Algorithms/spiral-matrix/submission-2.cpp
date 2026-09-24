class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = -1, e = matrix[0].size(), s = matrix.size(), w = -1;
        vector<int> res{};

        int te = e * s;
        
        while (res.size() < te){
            for (int i = w + 1; i < e; i++)
                res.push_back(matrix[n + 1][i]);
            n++;
            for (int i = n + 1; i < s; i++)
                res.push_back(matrix[i][e - 1]);
            e--;

            if (res.size() == te)
                return res;

            for (int i = e - 1; i > w; i--)
                res.push_back(matrix[s - 1][i]);
            s--;
            for (int i = s - 1; i > n; i--)
                res.push_back(matrix[i][w + 1]);
            w++;            
        }

        return res;
    }
};
