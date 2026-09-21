class Solution {
public:
    int step(int x){
        int y = 0;
        while (x){
            int d = x % 10;
            y += d * d;
            x /= 10;
        }
        return y;
    }
    bool isHappy(int n) {
        bitset<244> seen{};
        while (n > 243 or !seen[n]){
            if (n <= 243)
                seen[n] = true;
            n = step(n);
        }
        return n == 1;        
    }
};
