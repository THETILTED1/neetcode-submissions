class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s3.size() != s1.size() + s2.size())
            return false;
            
        if (s1.size() > s2.size())
            swap(s1, s2);
        
        int m = s1.size();
        int n = s2.size();

        vector<vector<bool>> seen(m + 1, vector<bool>(n + 1));
        
        queue<pair<int, int>> q{};
        q.emplace(0, 0);
        while (!q.empty()){
            auto pp = q.front();
            q.pop();
            
            if (pp.first > m or pp.second > n or seen[pp.first][pp.second])
                continue;
            
            int idx = pp.first + pp.second;

            if (pp.first < m and s1[pp.first] == s3[idx])
                q.emplace(pp.first + 1, pp.second);
            
        
            if (pp.second < n and s2[pp.second] == s3[idx])
                q.emplace(pp.first, pp.second + 1);
        
            seen[pp.first][pp.second] = true;
        }
        
        return seen[m][n];
    }
};
