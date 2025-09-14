class Solution {
        int solve(int i, int j, vector<vector<int>> &dp){
            if(i==0 and j==0) return 1;

            if(dp[i][j] != -1) return dp[i][j];

            int up = 0;
            int left = 0;

            if(i-1 >= 0){
                up = solve(i-1, j, dp);
            }
            if(j-1 >= 0){
                left = solve(i, j-1, dp);
            }

            dp[i][j] = up + left;
            return dp[i][j];

        }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(m-1, n-1, dp);

        
    }
};