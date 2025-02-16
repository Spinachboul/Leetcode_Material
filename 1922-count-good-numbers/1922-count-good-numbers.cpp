# define ll long long
// 5 choices for even numbers - 0,2,4,6,8
// 4 choices for odd numbers - 2,3,5,7
class Solution {
    const int MOD = 1e9+7;
    // function to find the power using exponentiation by squaring
    ll power(ll base, ll exp, ll mod){
        if(exp == 0) return 1;
        ll half = power(base, exp/2, mod);
        half = (half * half) % mod;
        return (exp % 2 == 0) ? half : (half* base)%mod;
    }
public:
    int countGoodNumbers(long long n) {
        ll evenCount = (n+1)/2;
        ll oddCount = (n)/2;
        ll evenWays = power(5, evenCount, MOD);
        ll oddWays = power(4, oddCount, MOD);
        return (evenWays * oddWays) % MOD;

        
    }

        
};