class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int, int>> st{};
        
        int mm = 0;

        for (int r = 0; r < heights.size(); r++){
            if (!st.empty() and heights[r] < st.top().first){
                pair<int, int> pp;
                while (!st.empty() and 
                        heights[r] < st.top().first){
                    pp = st.top();
                    mm = max(mm, pp.first * (r - pp.second));
                    st.pop();
                }
                if (st.empty() or st.top().first != heights[r]){
                    st.push({heights[r], pp.second});
                }
            }

            if (st.empty() or heights[r] != st.top().first){
                st.push({heights[r], r});
            }
        }

        while (!st.empty()){
            pair<int, int> pp = st.top();
            int a = pp.first * (heights.size() - pp.second);
            mm = max(mm, a);
            st.pop();
        }

        return mm;
    }
};
