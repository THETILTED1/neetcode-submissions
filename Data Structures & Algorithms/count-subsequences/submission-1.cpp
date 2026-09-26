class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.size();
        int n = t.size();
        if (m < n)
            return 0;

        vector<int> dp(m, 1);
        dp[0] = s[0] == t[0];
        for (int j = 1; j < m; j++)
            dp[j] = dp[j - 1] + (s[j] == t[0]);

        for (int i = 1; i < n; i++){
            int diag = dp[i - 1];
            dp[i - 1] = 0;
            for (int j = i; j < m; j++){
                int tmp = dp[j];
                dp[j] = dp[j - 1] + (s[j] == t[i]) * diag;
                diag = tmp;
            }
        }

        return dp[m - 1];
    }
};
