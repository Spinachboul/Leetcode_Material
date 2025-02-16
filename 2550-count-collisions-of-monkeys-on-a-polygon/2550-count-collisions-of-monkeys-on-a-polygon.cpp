class Solution {
    const int MOD = 1e9+7;
public:
    int monkeyMove(int n) {
        long res = 1, base = 2;
        while(n>0){
            if(n%2){
                res = res * base % MOD;
                
            }
            base = base * base % MOD;
            n>>=1;
        }
        return (res - 2 + MOD) % MOD;

        
    }
};