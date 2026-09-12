class Solution {
public:
    array<string, 8> combos{{
        "abc", "def", "ghi", "jkl", 
        "mno", "pqrs", "tuv", "wxyz"
    }};
    void dfs(vector<string>& r, string& p, string& s, int l){
        if (l == s.size()){
            r.push_back(p);
            return;
        }

        for (char c : combos[s[l] - '2']){
            p.push_back(c);
            dfs(r, p, s, l + 1);
            p.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) return {};
        string path = "";
        vector<string> res{};
        dfs(res, path, digits, 0);
        return res;
    }
};
