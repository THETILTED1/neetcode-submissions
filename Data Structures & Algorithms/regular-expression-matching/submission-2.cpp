class Solution {
public:
    bool isMatch(string s, string p) {
        reverse(s.begin(), s.end());
        reverse(p.begin(), p.end());

        int m = p.size();
        int n = s.size();

        vector<vector<bool>> dp(n, vector<bool>(m, false));
        vector<vector<bool>> seen(n, vector<bool>(m, false));
        stack<pair<int, int>> st{};
        st.emplace(0, 0);
        while (!st.empty()){
            //cout << "ne ";
            auto [i, j] = st.top();
            //cout << i << ' ' << j << '\n';
            st.pop();

            if (i == n and (j == m or p[j] == '*' and j + 2 == m))
                return true;

            if (i == n or j == m or seen[i][j])
                continue;

            if (p[j] == '*'){
                //st.emplace(i + 0, j + 1);
                //st.emplace(i + 1, j + 1);
                //st.emplace(i + 2, j + 1);
                //...
                //cout << "wc\n";
                for (int k = 0; i + k < n and 
                    (p[j + 1] == '.' or s[i + k] == p[j + 1]); k++){

                    st.emplace(i + k, j + 1);
                    ///cout << i + k << ' ' << j + 1 << '\n';
                }
                st.emplace(i, j + 2);
                //cout << i << ' ' << j + 2 << '\n';
            }

            if (s[i] == p[j] or p[j] == '.'){
                st.emplace(i + 1, j + 1);
                dp[i][j] = true;
                seen[i][j] = true;
            }
        }

        return false;
    }
};
