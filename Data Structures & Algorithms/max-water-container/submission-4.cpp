class Solution {
public:
    int maxArea(vector<int>& heights) {
        int a = 0, b = heights.size() - 1;
        int mv = 0;
        while (a < b){
            int v = (b - a) * min(heights[a], heights[b]);
            mv = max(v, mv);
            bool hh = heights[a] < heights[b];
            a += hh;
            b -= !hh;
        }

        return mv;
    }
};
