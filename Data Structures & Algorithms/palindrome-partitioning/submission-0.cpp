class Solution {
public:
    vector<vector<string>> res{};

    bool issym(string s, int l, int r){
        for (int i = 0; i <= r - l; i++){
            if (s[l + i] != s[r - i])
                return false;
        }
        return true;
    }

    void dfs(string s, int l, vector<string>& p){
        if (l == s.size()){
            res.push_back(p);
            return;
        }

        for (int i = l; i < s.size(); i++){
            if (issym(s, l, i)){
                p.push_back(s.substr(l, i - l + 1));
                dfs(s, i + 1, p);
                p.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<string> path{};
        dfs(s, 0, path);
        return res;
    }
};
