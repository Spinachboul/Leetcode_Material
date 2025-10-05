class Solution {
vector<int> xdir = {-1, 1, 0, 0};
vector<int> ydir = {0, 0, 1, -1};

private:
    void dfs(int row, int col, vector<vector<int>>& h, vector<vector<bool>>& vis){
        int m = h.size();
        int n = h[0].size();
        vis[row][col] = true;

        for(int i=0 ; i<4 ; i++){
            int xx = xdir[i];
            int yy = ydir[i];
            int newX = row + xx;
            int newY = col + yy;

            if(newX < 0 || newX >=m || newY < 0 || newY >=n) continue;
            if(vis[newX][newY]) continue;

            if(h[newX][newY] < h[row][col]) continue;

            dfs(newX, newY, h, vis);
        }
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        /*
        Pseudocode

        what is my grid: it is this heights vector<vector<int>> given in the problem

        how should I start my dfs approach : create visited vector<vector<int>> and mark the vis as true for every cell

        how should I write the directions: just simply write them as different vectors depending on the questions
        */

        int m = heights.size();
        int n = heights[0].size();

        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));

        for(int i=0 ; i<n ; i++) dfs(0, i, heights, pacific);
        for(int i=0 ; i<m ; i++) dfs(i, 0, heights, pacific);
        for(int i=0 ; i<n ; i++) dfs(m-1, i, heights, atlantic);
        for(int i=0 ; i<m ; i++) dfs(i, n-1, heights, atlantic);

        vector<vector<int>> res;
        for(int i=0 ; i<m ; i++){
            for(int j=0 ; j<n ; j++){
                if(pacific[i][j] && atlantic[i][j]){
                    res.push_back({i, j});
                }
            }
        }
        return res;

        
        
        
    }
};