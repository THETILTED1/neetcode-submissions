

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        vector<uint64_t> data{};
        data.assign(nums.size() / 64 + 1, 0ULL);

        for (int n : nums){
            int w = n >> 6;
            int r = n & 63;

            if ((data[w] >> r) & 1){
                return n;
            }

            data[w] ^= (1ULL << r);
        }

        return -1;
    }
};
