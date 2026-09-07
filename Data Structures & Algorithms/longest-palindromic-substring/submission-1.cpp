class Solution {
public:
    string longestPalindrome(string s) {
        string best = "";

        int sz = s.size();

        int x, y;
        
        for (int i = 0; i < s.size(); i++){
            x = i - 1;
            y = i + 1;
            while (x >= 0 and y < sz and s[x] == s[y]){
                x--;
                y++;
            }

            if (y - x - 1 > best.size()){
                best = s.substr(x + 1, y - x - 1);
                // cout << best << ' ';
            }
        }

        for (int i = 0; i < s.size() - 1; i++){
            if (s[i] != s[i + 1]) continue;
            x = i - 1;
            y = i + 2;
            while (x >= 0 and y < sz and s[x] == s[y]){
                x--;
                y++;
            }
            
            if (y - x - 1 > best.size()){
                best = s.substr(x + 1, y - x - 1);
                // cout << best << ' ';
            }
        }

        return best;
    }
};
