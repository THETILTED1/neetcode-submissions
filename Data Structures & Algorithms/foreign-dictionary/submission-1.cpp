class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        array<bitset<26>, 26> adj{};
        array<int, 26> in{};
        bitset<26> has{};

        for (const string& s : words)
            for (const char& c : s)
                has[c - 'a'] = true;

        for (int i = 0; i < words.size() - 1; i++){
            const string& u = words[i];
            const string& v = words[i + 1];
            int j = 0;
            for (; j < min(u.size(), v.size()) and u[j] == v[j]; j++);
            if (j == u.size())
                continue;
            if (j == v.size())
                return "";
            
            auto& l = adj[u[j] - 'a'];

            in[v[j] - 'a'] += !l[v[j] - 'a'];
            l[v[j] - 'a'] = true;
        }

        string res = "";
        for (int i = 0; i < 26; i++)
            if (has[i] and in[i] == 0)
                res.push_back(static_cast<char>(i + 'a'));
        
        int l = 0, r = res.size();
        while (l < r){
            int c = res[l] - 'a';
            l++;

            for (int i = 0; i < 26; i++)
                if (adj[c][i]){
                    in[i]--;
                    if (in[i] == 0){
                        res.push_back(static_cast<char>(i + 'a'));
                        r++;
                    }
                }
        }

        if (r != has.count())
            return "";
        return res;  
    }
};
