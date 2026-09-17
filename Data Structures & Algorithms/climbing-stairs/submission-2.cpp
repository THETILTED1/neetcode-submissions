class Solution {
public:
    int climbStairs(int n) {
        if (n < 2) 
            return 1;

        int x = 1, y = 1;
        for (int i = 2; i <= n; i++){
            int tmp = x;
            x += y;
            y = tmp;
        }
        return x;        
    }
};
