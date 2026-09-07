class Solution {
public:
    int trap(vector<int>& height) {
        int sz = height.size();
        int a = 0, b = sz - 1;
        int ma = -2, mb = -1;
        int v = 0;

        while (a < b){
            while (ma < mb and a <= b){
                int ca = height[a];
                ma = max(ma, ca);
                v += (ma - ca);
                a++;
            }
            while (ma >= mb and a <= b){
                int cb = height[b];
                mb = max(mb, cb);
                v += (mb - cb);
    
                b--;
            }
        }

        return v;
    }
};
