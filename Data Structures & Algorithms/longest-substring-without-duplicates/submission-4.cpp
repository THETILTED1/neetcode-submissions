class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> has{};
        int a = 0, b = 0;
        int ml = 0;
        while (b < s.size()){
            if (has.contains(s[b])){
                if (has[s[b]] >= a)
                    a = has.at(s[b]) + 1;
                has[s[b]] = b;
                b++;
                ml = max(b - a, ml);
            } else {
                has.insert({s[b], b});
                b++;
                ml = max(b - a, ml);
            }
        }

        return ml;
    }
};
