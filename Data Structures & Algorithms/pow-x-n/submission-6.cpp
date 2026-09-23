class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0)
            return 1.0;
        if (x == 0.0)
            return 0.0;
        
        double r = 1.0;
        double xx = x;
        bool sgn = n > 0;
        uint32_t nn = static_cast<uint32_t>(abs(n));
        for (int i = 0; i < 32; i++){
            if ((1U << i) & nn)
                r *= xx;
            xx *= xx;
        }

        return sgn ? r : 1/r;
    }
};
