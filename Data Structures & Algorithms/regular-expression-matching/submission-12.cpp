class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<bool> dp(m + 1, false);
        dp[0] = true;
        for (int j = 1; j <= m; j++)
            dp[j] = p[j-1] == '*' and dp[j-2];
        
        bool diag;
        for (int i = 1; i <= n; i++){
            diag = dp[0];
            dp[0] = false;
            for (int j = 1; j <= m; j++){
                bool tmp = dp[j];
                if (p[j-1] == '*'){
                    bool copy = s[i-1] == p[j-2] or p[j-2] == '.';
                    dp[j] = dp[j] and copy or (j > 1) and dp[j-2];
                } else {
                    bool match = s[i-1] == p[j-1] or p[j-1] == '.';
                    dp[j] = diag and match;
                }
                diag = tmp;
            }
        }

        return dp[m];
    }
};
