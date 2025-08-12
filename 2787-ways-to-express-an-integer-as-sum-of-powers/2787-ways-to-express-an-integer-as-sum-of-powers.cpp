class Solution {
public:
    int numberOfWays(int n, int x) {

        vector<vector<int>> dp(n+1, vector<int>(n+1));

        dp[0][0] = 1;
        long long MOD = 1e9+7;
        for(int i=1 ; i<=n ; i++){
            long long val = pow(i, x);
            for(int j=0 ; j<=n ; j++){
                dp[i][j] = dp[i-1][j];
                if(j >= val){
                    dp[i][j] = (dp[i][j]+ dp[i-1][j-val]) % MOD;
                }
            }
        }
        return dp[n][n];

        
    }
};