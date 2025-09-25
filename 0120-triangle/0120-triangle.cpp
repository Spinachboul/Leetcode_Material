class Solution {
private:
    int dfs(int i, int j, vector<vector<int>> &t, vector<vector<int>> &dp){
        int n = t.size();
        if(i==n-1) return t[i][j];
        if(dp[i][j] != INT_MAX) return dp[i][j];

        int down = dfs(i+1, j, t, dp);
        int downR = dfs(i+1, j+1, t, dp);

        dp[i][j] = t[i][j] + min(down, downR);

        return dp[i][j];

    }
public:
    int minimumTotal(vector<vector<int>>& t) {

        vector<vector<int>> dp(t.size(), vector<int>(t.size(), INT_MAX));
        return dfs(0, 0, t, dp);

        
    }
};