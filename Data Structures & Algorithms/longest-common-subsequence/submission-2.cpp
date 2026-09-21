class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        if (text1.size() > text2.size())
            swap(text1, text2);

        int m = text1.size();
        int n = text2.size();
        vector<int> dp(m);
        dp[0] = text1[0] == text2[0];
        for (int j = 1; j < m; j++)
            dp[j] = max(dp[j - 1], (int)(text1[j] == text2[0]));

        for (int i = 1; i < n; i++){
            int prev = dp[0];
            dp[0] = max(dp[0], (int)(text1[0] == text2[i]));
            for (int j = 1; j < m; j++){
                int tmp = dp[j];
                int diag = (text1[j] == text2[i]) + prev;
                dp[j] = max({dp[j], dp[j - 1], diag});
                prev = tmp;
            }
        }
        
        return dp[m - 1];
    }
};
