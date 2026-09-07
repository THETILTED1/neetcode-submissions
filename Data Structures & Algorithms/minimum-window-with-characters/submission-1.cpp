class Solution {
public:
    string minWindow(string s, string t) {
        if (t.size() > s.size()){ return ""; }
        unordered_map<char, int> counts{};
        for (int i = 0; i < t.size(); i++)
            counts[t[i]]++;
        
        unordered_map<char, queue<int>> places{};

        int l; // the minimum of all queues
        int bl; // best l
        int kk = s.size() + 1; // ideal length

        int mm = 0; // matches

        unordered_map<char, int> has{};

        for (int r = 0; r < s.size(); r++){
            if (counts.contains(s[r])){
                mm -= (counts[s[r]] == has[s[r]]);
                has[s[r]]++;
                mm += (counts[s[r]] == has[s[r]]);

                if (places[s[r]].size() == counts[s[r]]){
                    places[s[r]].pop();
                    has[s[r]]--;
                    mm += 1;
                }
                places[s[r]].push(r);

                if (mm == counts.size()){ // matched all
                    int l = s.size();
                    for (const auto& cc : places){
                        l = min(cc.second.front(), l);
                    }
                    if (r - l + 1 < kk){
                        bl = l;
                        kk = r - l + 1;
                    }
                }
            }
        }

        if (kk == s.size() + 1){ return ""; }
        return s.substr(bl, kk);
    }
};
