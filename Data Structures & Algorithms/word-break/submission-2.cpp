class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int sz = s.size();

        unordered_map<int, unordered_set<string>> wd{};
        for (string& t : wordDict) 
            wd[t.size()].insert(t);

        unordered_set<int> dp{};
        dp.insert(sz);
    
        for (int l = sz - 1; l >= 0; l--){
            for (const auto& pp : wd){
                if (dp.contains(l + pp.first) and 
                    pp.second.contains(s.substr(l, pp.first))){

                    dp.insert(l);
                    break;
                }
            }
        }
        return dp.contains(0);
    }
};
