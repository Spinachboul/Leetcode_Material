class Solution {
public:
    int countVowelStrings(int n) {
        int dp[n+1][5];
        // a->0, e->1, i->2, o->3, u->4
        dp[1][0] = dp[1][1] = dp[1][2] = dp[1][3] = dp[1][4] = 1;
        for(int i=2; i<=n; ++i){
            dp[i][0] = dp[i-1][0];
            dp[i][1] = dp[i-1][0] + dp[i-1][1];
            dp[i][2] = dp[i-1][0] + dp[i-1][1] + dp[i-1][2];
            dp[i][3] = dp[i-1][0] + dp[i-1][1] + dp[i-1][2] + dp[i-1][3];
            dp[i][4] = dp[i-1][0] + dp[i-1][1] + dp[i-1][2] + dp[i-1][3] + dp[i-1][4];
        }
        int ans = dp[n][0] + dp[n][1] + dp[n][2] + dp[n][3] + dp[n][4];
        return ans;
    }
};