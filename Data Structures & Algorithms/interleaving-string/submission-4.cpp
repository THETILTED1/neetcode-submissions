class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s3.size() != s1.size() + s2.size())
            return false;
        
        if (s1.size() > s2.size())
            swap(s1, s2);

        int m = s1.size();
        int n = s2.size();

        vector<bool> dp(m + 1, false);
        dp[0] = true;
        for (int j = 1; j <= m; j++)
            dp[j] = dp[j - 1] and s1[j - 1] == s3[j - 1];
        
        for (int i = 1; i <= n; i++){
            dp[0] = dp[0] and s2[i - 1] == s3[i - 1];
            for (int j = 1; j <= m; j++)
                dp[j] = (dp[j - 1] and s1[j - 1] == s3[i + j - 1]) or
                    (dp[j] and s2[i - 1] == s3[i + j - 1]);
        }
            
        return dp[m];
    }
};
