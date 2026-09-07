class Solution {
public:
    double myPow(double x, int n) {
        if (x == 0){ return 0; }
        if (n == 0){ return 1.0; }

        bool sgn = n > 0;
        long long pn = n;
        if (!sgn) pn = -pn;
        double r = 1.0;
        double xx = x;
        for (int i = 0; (1LL << i) <= pn && i < 63; i++){
            if ((pn >> i) & 1)
                r *= xx;

            xx *= xx;
        }
        return sgn ? r : 1.0 / r;
    }
};