class Solution {
public:
    int countSubstrings(string s) {
        int sz = s.size();

        int x, y;
        int m = 0;
        
        for (int i = 0; i < s.size(); i++){
            x = y = i;
            while (x >= 0 and y < sz and s[x] == s[y]){
                m++;
                x--; y++;
            }
        }

        for (int i = 0; i < s.size() - 1; i++){
            if (s[i] != s[i + 1]) continue;
            x = i;
            y = i + 1;
            while (x >= 0 and y < sz and s[x] == s[y]){
                m++;
                x--; y++;
            }
            
        }

        return m;
    }
};
