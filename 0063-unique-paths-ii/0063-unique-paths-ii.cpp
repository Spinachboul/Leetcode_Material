class Solution {
private:
    int dd(int i, int j, vector<vector<int>> &g, vector<vector<int>> &dp){
        if(i==0 and j==0) return dp[0][0];
        if(dp[i][j] != -1) return dp[i][j];

        int up = 0, left = 0;
        if(i>=1 && g[i-1][j] == 0){
            up = dd(i-1, j, g, dp);
        }
        if(j>=1 && g[i][j-1] == 0){
            left = dd(i, j-1, g, dp);
        }
        return dp[i][j] = up + left;
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& g) {
        int n = g.size();
        int m = g[0].size();
        vector<vector<int>> dp(n , vector<int>(m, -1));

        if(g[0][0] == 1 || g[n-1][m-1] == 1) return 0;
        dp[0][0] = 1;
        return dd(n-1, m-1, g, dp);
    }
};