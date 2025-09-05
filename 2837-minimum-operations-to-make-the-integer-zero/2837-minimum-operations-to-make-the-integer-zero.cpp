class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        // if(num2 >= num1) return 0;

        int ans = 1;
        while(1){
            long long x = num1 - static_cast<long long>(num2) * ans;
            if(x < ans){
                return -1;
            }
            if(ans >= __builtin_popcountll(x)) return ans;
            ans++;
        }




        
    }
};