#include <unordered_map>

class Solution {
public:
    bool isAnagram(string s, string t) {
        std::unordered_map<char, int> ss{}, ts{};
        for (char c : s){
            if (ss.contains(c)){
                ss[c]++;
            } else {
                ss.insert({c, 1});
            }
        }

        for (char c : t){
            if (ts.contains(c)){
                ts[c]++;
            } else {
                ts.insert({c, 1});
            }
        }

        return (ts == ss);
    }
};
