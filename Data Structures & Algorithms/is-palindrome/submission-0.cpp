class Solution {
public:
    bool lowercase(char c){ return (c >= 'a') && (c <= 'z'); }
    bool uppercase(char c){ return (c >= 'A') && (c <= 'Z'); }
    bool numeric(char c){ return (c >= '0') && (c <= '9'); }
    bool validchar(char c){
        return lowercase(c) or uppercase(c) or numeric(c);
    }
    bool isPalindrome(string s) {
        int a = 0, b = s.size() - 1;
        char ca, cb;
        while (a < b){
            while (!validchar(s[a]) and (a < s.size())){
                a++;
            }
            while (!validchar(s[b]) and (b >= 0)){
                b--;
            }
            ca = s[a] + uppercase(s[a]) * ('a' - 'A');
            cb = s[b] + uppercase(s[b]) * ('a' - 'A');
            if (ca != cb){
                return false;
            }
            a++;b--;
        }

        

        return true;
    }
};
