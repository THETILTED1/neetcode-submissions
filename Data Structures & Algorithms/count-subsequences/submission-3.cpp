class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.size();
        int n = t.size();
        if (m < n)
            return 0;

        vector<int> dp(n + 1);
        dp[0] = 1;
        for (int i = 1; i <= m; i++)
            for (int j = n; j > 0; j--)
                dp[j] += dp[j - 1] * (s[i - 1] == t[j - 1]);
            
        return dp[n];
    }
};
