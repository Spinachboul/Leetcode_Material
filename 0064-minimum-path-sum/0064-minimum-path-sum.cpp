class Solution {
private:
    int solve(int i , int j, vector<vector<int>> &dp, vector<vector<int>> &g){
        int n = g.size(), m = g[0].size();
        if(i>=g.size() || j >= g[0].size()){
            return 1e9;
        }
        if(i==n-1 && j==m-1)return g[i][j];
        if(dp[i][j] != -1) return dp[i][j];

        int down = solve(i+1, j, dp, g);
        int right = solve(i, j+1, dp, g);

        dp[i][j] = g[i][j] + min(down, right);
        return dp[i][j];
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp(201, vector<int>(201, -1));
        return solve(0, 0, dp, grid);

    }
};