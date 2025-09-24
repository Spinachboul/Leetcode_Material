class Solution {
public:
    int reverseBits(int n) {
        uint32_t res = 0;
        for(int i=0 ; i<32; i++){
            int bit = n & 1; // get the right most bit of n
            res = (res << 1); // perform the left shift on res
            res = res | bit; // add the bit to res
            n >>= 1; // right shift to move on to the next bit
        }
        return res;
        
    }
};