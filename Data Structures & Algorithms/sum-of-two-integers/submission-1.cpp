class Solution {
public:
    int getSum(int a, int b) {
        int c = a & b;
        int s = a ^ b;
        while (c){
            int tmp = (c << 1);
            c = s & tmp;
            s ^= tmp;
        }
        return s;
    }
};
