class Solution {
public:
    array<vector<string>, 8> combos{{
        {"a", "b", "c"},
        {"d", "e", "f"},
        {"g", "h", "i"},
        {"j", "k", "l"},
        {"m", "n", "o"},
        {"p", "q", "r", "s"},
        {"t", "u", "v"},
        {"w", "x", "y", "z"}
    }};

    void append(vector<string>& l, char d){
        int n = l.size();
        for (int i = 0; i < n; i++){
            for (auto& c : combos[d - '2']){
                l.push_back(l[i] + c);
            }
        }
        l.erase(l.begin(), l.begin() + n);
    }

    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) return {};

        vector<string> res = combos[digits[0] - '2'];
        for (int i = 1; i < digits.size(); i++)
            append(res, digits[i]);
        
        return res;
    }
};
