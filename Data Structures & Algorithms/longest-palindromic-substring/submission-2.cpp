class Solution {
public:
    string longestPalindrome(string s) {
        string best = "";

        int sz = s.size();

        int x, y;
        
        for (int i = 0; i < s.size(); i++){
            x = y = i;
            while (--x >= 0 & ++y < sz and s[x] == s[y]);

            if (y - x - 1 > best.size()){
                best = s.substr(x + 1, y - x - 1);
            }
        }

        for (int i = 0; i < s.size() - 1; i++){
            if (s[i] != s[i + 1]) continue;
            x = i;
            y = i + 1;
            while (--x >= 0 & ++y < sz and s[x] == s[y]);
            
            if (y - x - 1 > best.size()){
                best = s.substr(x + 1, y - x - 1);
            }
        }

        return best;
    }
};
