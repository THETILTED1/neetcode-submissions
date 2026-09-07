class Solution {
public:
    int nck(int n, int k){
        uint64_t r = 1;
        for (int i = 1; i <= k; i++){
            r *= (n - i + 1);
            r /= i;
        }
        return static_cast<int>(r);
    }
    int uniquePaths(int m, int n) {
        return nck(m + n - 2, min(m, n) - 1);
    }
};
