class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int fc = -1, fr = -1;

        int m = matrix.size();
        int n = matrix[0].size();

        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (matrix[i][j] == 0){
                    if (fc < 0 and fr < 0){
                        fr = i;
                        fc = j;
                    }

                    matrix[i][fc] = 0;
                    matrix[fr][j] = 0;
                    break;
                }  
            }
        }

        for (int i = 0; i < m; i++){
            if (matrix[i][fc] == 0 and i != fr)
                matrix[i].assign(n, 0);
        }
        for (int j = 0; j < n; j++){
            if (matrix[fr][j] == 0){
                for (int i = 0; i < m; i++){
                    matrix[i][j] = 0;
                }
            }
        }
        matrix[fr].assign(n, 0);

    }
};
