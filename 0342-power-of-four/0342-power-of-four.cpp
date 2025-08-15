class Solution {
public:
    bool isPowerOfFour(int n) {
        n = n % 100005;
        return n > 0 && (n & (n-1)) == 0 && (n & 0x5555555);
        
        
    }
};