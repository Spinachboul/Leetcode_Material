class Solution {
public:
    bool isPowerOfThree(int n) {
        int power = 20;
        while(power--){
            long long exp = pow(3, power);
            if(n == exp) return true;
            
        }
        return false;
        
    }
};