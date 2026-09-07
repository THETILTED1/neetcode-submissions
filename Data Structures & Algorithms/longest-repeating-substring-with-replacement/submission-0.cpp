class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> counts{};
        unordered_map<int, unordered_set<char>> levels{};

        int l = 0; // left
        int v = 0; // dominant count
        int d = 0; // discrepancy

        int x = 0;

        int r = 0;
        while (r < s.size()){
            int cc = counts[s[r]];
            counts[s[r]]++;
            levels[cc].erase(s[r]);
            levels[cc + 1].insert(s[r]);

            if (cc + 1 > v){ // new dominant
                d += v;
                d -= cc;
                v = cc + 1; 
            } else { // adds to discrepancy
                d += 1;
            }

            r += 1;

            if (d > k){ // not going well
                int dd = counts[s[l]];
                counts[s[l]] -= 1;
                levels[dd].erase(s[l]);
                levels[dd - 1].insert(s[l]);

                if (dd == v and levels[dd].empty()){
                    v -= 1;
                } else {
                    d -= 1;
                }

                l += 1;
            }  

            x = max(x, r - l);          
        }
        
        return x;
    }
};
