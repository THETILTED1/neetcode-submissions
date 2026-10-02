class Solution {
public:
    bool isMatch(string s, string p) {
        int m = p.size();
        int n = s.size();

        vector<vector<bool>> seen(n, vector<bool>(m, false));
        stack<pair<int, int>> st{};
        st.emplace(0, 0);
        while (!st.empty()){
            auto [i, j] = st.top();
            st.pop();

            if (i == n and (j == m or p[j + 1] == '*' and j + 2 == m))
                return true;

            if (i == n or j == m or seen[i][j])
                continue;

            if (p[j + 1] == '*'){
                if (s[i] == p[j] or p[j] == '.')
                    st.emplace(i + 1, j);
                st.emplace(i, j + 2);
                seen[i][j] = true;
                continue;
            }

            if (s[i] == p[j] or p[j] == '.'){
                st.emplace(i + 1, j + 1);                    
            }
            seen[i][j] = true;
        }

        return false;
    }
};