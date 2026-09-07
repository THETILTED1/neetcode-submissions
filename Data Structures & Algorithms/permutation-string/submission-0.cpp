class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()){
            return false;
        }

        unordered_map<char, int> embed{};
        for (char c : s1){
            embed[c] += 1;
        }

        int sz = s1.size();

        unordered_map<char, int> roll{};
        for (int i = 0; i < sz; i++){
            roll[s2[i]] += 1;
        }

        if (roll == embed){ return true; }

        for (int r = sz; r < s2.size(); r++){
            roll[s2[r - sz]]--;
            if (roll[s2[r - sz]] == 0) {
                roll.erase(s2[r - sz]);
            }
            roll[s2[r]]++;
            if (roll == embed){
                return true;
            }
        }

        return false;
    }
};
