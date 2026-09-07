class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result{};
        std::unordered_map<std::string, int> ind{};
        int num = 0;

        for (std::string s : strs){
            string t = transform(s);
            if (ind.contains(t)){
                result[ind[t]].push_back(s);
            } else {
                ind.insert({t, num});
                result.push_back({s});
                num++;
            }
        }

        return result;
    }

    std::string transform(std::string s){
        std::sort(s.begin(), s.end());
        return s;    
    }
};
