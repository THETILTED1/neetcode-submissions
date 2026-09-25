class Solution {
public:
    bool checkValidString(string s) {
        int bal = 0;
        int cts = 0;
        for (int i = 0; i < s.size(); i++){
            bal += (s[i] == '(');
            cts += (s[i] == '*');
            bal -= (s[i] == ')');
            if (bal + cts < 0)
                return false;
        }
        bal = 0;
        cts = 0;
        for (int i = s.size() - 1; i >= 0; i--){
            bal += (s[i] == ')');
            cts += (s[i] == '*');
            bal -= (s[i] == '(');
            if (bal + cts < 0)
                return false;
        }
        return true;
    }
};

// (((((*(*********((*(((((****"