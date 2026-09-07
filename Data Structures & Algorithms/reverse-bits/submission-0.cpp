class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t fours = 0x0F0F0F0FU;
        uint32_t twos = 0x33333333U;
        uint32_t ones = 0x55555555U;
       
        uint64_t k = byteswap(static_cast<uint64_t>(n)) >> 32;
        n = static_cast<uint32_t>(k);

        n = ((n & ~ones) >> 1) | ((n & ones) << 1);
        n = ((n & ~twos) >> 2) | ((n & twos) << 2);
        n = ((n & ~fours) >> 4) | ((n & fours) << 4);

        return n;
    }
};
