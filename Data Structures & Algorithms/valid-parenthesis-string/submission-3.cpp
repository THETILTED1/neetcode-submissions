class Solution {
public:
    bool checkValidString(string s) {
        int upper = 0;
        int lower = 0;
        for (char c : s){
            upper += (c == '(');
            lower += (c == '(');

            upper -= (c == ')');
            lower -= (c == ')');

            upper += (c == '*');
            lower -= (c == '*');

            lower = max(0, lower);
            if (upper < 0)
                return false;
        }
        return lower == 0;
    }
};
