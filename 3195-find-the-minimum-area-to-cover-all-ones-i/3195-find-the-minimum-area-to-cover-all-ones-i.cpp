class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int maxI = 0, minI = n, maxJ = 0, minJ = m;
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(grid[i][j] == 1){
                    minI = min(minI, i);
                    maxI = i;
                    // maxI = max(maxI, i);
                    minJ = min(minJ , j);
                    maxJ = max(maxJ, j);
                }
            }
        }
        return (maxI - minI + 1) * (maxJ - minJ + 1);

        
    }
};