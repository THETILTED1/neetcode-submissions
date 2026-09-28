class Solution {
public:
    int minDistance(string word1, string word2) {
        if (word1.size() > word2.size())
            swap(word1, word2);
        
        int m = word1.size();
        int n = word2.size();

        vector<int> dp(m + 1);
        iota(dp.begin(), dp.end(), 0);

        for (int i = 1; i <= n; i++){
            int diag = i - 1;
            int insert = dp[0] = i;
            for (int j = 1; j <= m; j++){
                diag += !(word1[j - 1] == word2[i - 1]);
                int del = dp[j];
                dp[j] = min({diag, insert + 1, del + 1});
                diag = del;
                insert = dp[j];
            }
        }       

        return dp[m];
    }
};
