class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        vector<vector<int>> dp(m, vector<int>(n));
        dp[0][0] = text1[0] == text2[0];
        for (int i = 1; i < m; i++)
            dp[i][0] = max(dp[i - 1][0], (int)(text1[i] == text2[0]));
        for (int j = 1; j < n; j++)
            dp[0][j] = max(dp[0][j - 1], (int)(text1[0] == text2[j]));

        int best = 0;

        for (int i = 1; i < m; i++){
            for (int j = 1; j < n; j++){
                int diag = (text1[i] == text2[j]) + dp[i - 1][j - 1];
                int up = dp[i - 1][j];
                int left = dp[i][j - 1];
                dp[i][j] = max({diag, up, left});                
            }
        } 
        return dp[m - 1][n - 1];
    }
};
