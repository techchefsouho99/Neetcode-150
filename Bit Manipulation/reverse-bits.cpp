class Solution {
#include <cmath>
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res=0;
        for (int i = 0; i < 32; i++) {
            res <<= 1;           // Left shift result to make room for the next bit
            res |= (n & 1);      // Append the last bit of 'n' to 'res'
            n >>= 1;             // Right shift 'n' to get the next bit
        }
        return res;
    }
};