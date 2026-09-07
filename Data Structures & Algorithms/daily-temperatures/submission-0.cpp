class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size());
        stack<int> st{};

        for (int i = 0; i < temperatures.size(); i++){
            while (!st.empty() and 
                temperatures[st.top()] < temperatures[i]){

                int kk = st.top();
                res[kk] = i - kk;
                st.pop();
            }
            st.push(i);
        }
        
        while (!st.empty()){
            int kk = st.top();
            res[kk] = 0;
            st.pop();
        }

        return res;
    }
};
