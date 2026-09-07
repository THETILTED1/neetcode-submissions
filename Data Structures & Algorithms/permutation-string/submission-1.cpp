class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()){
            return false;
        }
        array<int, 26> embed{};
        array<int, 26> roll{};
        int sz = s1.size();
        for (int i = 0; i < sz; i++){
            embed[s1[i] - 'a']++;
            roll[s2[i] - 'a']++;
        }

        int mm = 0;
        for (int i = 0; i < 26; i++){
            mm += embed[i] == roll[i];
        }
        if (mm == 26){ return true; }
        for (int r = sz; r < s2.size(); r++){
            char c = s2[r - sz];
            char d = s2[r];

            mm -= (embed[c - 'a'] == roll[c - 'a']);
            roll[c - 'a'] -= 1;
            mm += (embed[c - 'a'] == roll[c - 'a']);

            mm -= (embed[d - 'a'] == roll[d - 'a']);
            roll[d - 'a'] += 1;
            mm += (embed[d - 'a'] == roll[d - 'a']);

            if (mm == 26){ return true; }          
        }
        return false;
    }
};
