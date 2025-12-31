class Solution {
private:
    bool canCross(int m, int n, vector<vector<int>>& cells, int day){
        // create grid (0 = land, 1 = water)

        vector<vector<int>> grid(m, vector<int>(n, 0));

        for(int i=0 ; i<day ; i++){
            int r = cells[i][0] - 1;
            int c = cells[i][1] - 1;

            grid[r][c] =1;
        }

        queue<pair<int, int>> q;
        
        // add all the valid startung points from top row 
        for(int j=0 ; j < n ; j++){
            if(grid[0][j] == 0){
                q.push({0, j});
                grid[0][j] = 1; // mark as visited

            }

        }

        int dr[] = {-1, 1, 0 , 0};
        int dc[] = {0, 0, -1, 1};

        // BFS
        while(!q.empty()){
            auto [r, c] = q.front();

            q.pop();

            if(r == m-1) return true;

            for(int i=0 ; i<4 ; i++){
                int nr = r + dr[i];
                int nc = c  + dc[i];

                if(nr < m  && nr >=0 && nc < n && nc >=0 && grid[nr][nc] == 0){
                    // mark as visited means make it water
                    grid[nr][nc] = 1;
                    q.push({nr, nc});
                }
            }
        }
        return false;


    }
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int m = row;
        int n = col;

        int left =1 ;
        int right = cells.size();

        int ans = 0;
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(canCross(m,n, cells, mid)){
                ans = mid;
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }

        return ans;

        
        


    }
};