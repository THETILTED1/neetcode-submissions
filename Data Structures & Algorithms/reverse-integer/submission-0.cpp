class Solution {
public:
    bool oob(string s){
        const string neg = to_string(1 << 31);
        const string pos = to_string(INT_MAX);

        if (s[0] == '-'){
            return (s.size() > neg.size())
                or ((s.size() == neg.size()) and 
                    (s > neg));
        }

        return (s.size() > pos.size())
                or ((s.size() == pos.size()) and 
                    (s > pos));
            
    }
    int reverse(int x) {
        if (x == 0){ return 0; }
        string rx = "";
        if (x < 0){ rx += '-'; }
        x = x * (((x > 0) << 1) - 1);
        while (x){
            rx += (char)(x % 10 + '0');
            x /= 10;
        }
        if (oob(rx)){ return 0; }
        return stoi(rx);
    }
};
