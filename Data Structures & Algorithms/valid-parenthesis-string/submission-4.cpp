class Solution {
public:
    bool checkValidString(string s) {
        int upper = 0;
        int lower = 0;
        for (char c : s){
            if (c == '('){
                upper++;
                lower++;
            } else if (c == ')'){
                upper--;
                lower--;
            } else {
                upper++;
                lower--;
            }

            lower = max(0, lower);
            if (upper < 0)
                return false;
        }
        return lower == 0;
    }
};
