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
        while ((n = step(n)) != 1 and n != 4);
        return n == 1;
    }
};
