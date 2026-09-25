class Solution {
public:
    vector<int> partitionLabels(string s) {
        array<int, 26> freq{};
        int has = 0;

        vector<int> res{};

        for (char c : s)
            freq[c - 'a']++;

        int cts = 0;
        
        for (char c : s){
            int i = c - 'a';
            freq[i]--;
            has |= (1 << i);
            cts++;

            if (!freq[i]){
                has &= ~(1 << i);
                if (!has){
                    res.push_back(cts);
                    cts = 0;
                }
            }
        }

        return res;
    }
};
