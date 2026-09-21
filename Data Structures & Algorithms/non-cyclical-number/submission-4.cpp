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
        int fast, slow;
        fast = slow = n;
        do {
            fast = step(step(fast));
            slow = step(slow);
        } while (fast != slow);

        return fast == 1;  
    }
};
