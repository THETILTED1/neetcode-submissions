class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int sz = s.size();
        unordered_set<string> wd(wordDict.begin(), wordDict.end());
        unordered_set<int> dp{};
        dp.insert(sz);
    
        for (int l = sz - 1; l >= 0; l--){
            for (int i : dp){
                if (wd.contains(s.substr(l, i - l)))
                    dp.insert(l);
            }
        }
        return dp.contains(0);
    }
};
