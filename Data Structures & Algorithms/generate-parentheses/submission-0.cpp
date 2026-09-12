class Solution {
public:
    void dfs(vector<string>& res, string p, int k, int m){
        if (k == 0){
            for (int i = 0; i < m; i++)
                p += ')';
            res.push_back(p);
            return;
        }

        if (k > 0)
            dfs(res, p + '(', k - 1, m + 1);

        if (m > 0)
            dfs(res, p + ')', k, m - 1);
    }

    vector<string> generateParenthesis(int n) {
        vector<string> res{};
        dfs(res, "", n, 0);
        return res;
    }
};
