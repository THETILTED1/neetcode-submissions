class Solution {
public:
    int minDistance(string word1, string word2) {
        if (word1.size() > word2.size())
            swap(word1, word2);
        
        int m = word1.size();
        int n = word2.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int j = 0; j <= m; j++)
            dp[0][j] = j;       

        for (int i = 1; i <= n; i++){
            dp[i][0] = i;
            for (int j = 1; j <= m; j++){
                int diag = dp[i - 1][j - 1] + !(word1[j - 1] == word2[i - 1]);
                int insert = dp[i][j - 1] + 1;
                int del = dp[i - 1][j] + 1;
                dp[i][j] = min({diag, insert, del});
            }
        }

        return dp[n][m];
    }
};
