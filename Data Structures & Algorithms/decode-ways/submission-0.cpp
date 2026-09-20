class Solution {
public:
    bool getTwo(string s, int i){
        if (i + 2 > s.size() or i < 0 or s[i] < '1')
            return false;
        return (10 * (s[i] - '0') + s[i + 1] - '0') < 27;
    }
    bool getOne(string s, int i){
        if (i >= s.size() or i < 0)
            return false;
        return s[i] > '0';
    }
    int numDecodings(string s) {
        int two = 1, one = 1;
        for (int i = 0; i < s.size(); i++){
            int tmp = one;
            one = getOne(s, i) * one + getTwo(s, i - 1) * two;
            two = tmp;
        }
        return one;
    }
};
