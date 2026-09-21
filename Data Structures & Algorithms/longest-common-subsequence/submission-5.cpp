class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        if (text1.size() > text2.size())
            swap(text1, text2);

        int m = text1.size();
        int n = text2.size();
        vector<int> dp(m + 1, 0);
        for (int i = 1; i <= n; i++){
            int prev = 0;
            for (int j = 1; j <= m; j++){
                int tmp = dp[j];
                int diag = (text1[j - 1] == text2[i - 1]) + prev;
                dp[j] = max({dp[j], dp[j - 1], diag});
                prev = tmp;
            }
        }

        return dp[m];
    }
};
