class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res{};
        for (int i = 0; i < n + 1; i++){
            res.push_back(popcount(static_cast<uint32_t>(i)));
        }
        return res;
    }
};
