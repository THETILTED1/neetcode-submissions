class Solution {
public:
    int vol(int a, int b, vector<int>& h){
        return (b - a) * min(h[a], h[b]);
    }
    int maxArea(vector<int>& heights) {
        int a = 0, b = heights.size() - 1;
        int mv = 0;
        while (a < b){
            int v = vol(a, b, heights);
            mv = max(v, mv);
            bool hh = heights[a] < heights[b];
            a += hh;
            b -= !hh;
        }

        return mv;
    }
};
