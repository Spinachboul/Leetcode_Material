class Solution {
private:
    int dfs(vector<vector<int>> &grid, vector<vector<bool>> &vis, int i, int j, int query){
        int n = grid.size();
        int m = grid[0].size();

        if(i < 0 || i >= n || j < 0 || j >= m || vis[i][j] || grid[i][j] >= query) return 0;

        vis[i][j] = true;
        int count = 1;

        count += dfs(grid, vis, i+1, j, query);
        count += dfs(grid, vis, i, j+1, query);
        count += dfs(grid, vis, i-1, j, query);
        count += dfs(grid, vis, i, j-1, query);

        return count;
    }
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> ans(queries.size());
        vector<vector<bool>> vis(n, vector<bool> (m, false));
        // indices for the grid
        int i=0, j=0;
        for(int ii=0 ; ii<queries.size() ; ii++){
            int query = queries[ii];
            // reset the visited array every time for each query
            fill(vis.begin() , vis.end() , vector<bool> (m, false));
            ans[ii] = dfs(grid, vis, 0, 0, query);
        }
        return ans;

        
    }
};