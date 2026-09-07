class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> ids{};
        vector<pair<int, int>> counts{};

        for (int n : nums){
            if (ids.contains(n)){
                counts[ids[n]].first++;
            } else {
                ids.insert({n, counts.size()});
                counts.push_back({1, n});
            }
        }

        sort(counts.begin(), counts.end());
        vector<int> result{};
        for (int i = 0; i < k and i < counts.size(); i++){
            result.push_back(counts[counts.size() - 1 - i].second);
        }
        return result;
    }
};
