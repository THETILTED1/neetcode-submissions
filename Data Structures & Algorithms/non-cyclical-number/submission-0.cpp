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
        unordered_set<int> seen{};
        seen.insert(n);
        while (!seen.contains(n = step(n)))
            seen.insert(n);
        return n == 1;        
    }
};
