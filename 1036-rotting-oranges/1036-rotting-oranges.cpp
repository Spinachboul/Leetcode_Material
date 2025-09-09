class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        vector<int> dx = {1, 0, -1, 0};
        vector<int> dy = {0, 1, 0, -1};
        int minutes = 0;

        while (true) {
            bool changed = false;

            // Step 1: mark new rotting oranges as 3
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    if (grid[i][j] == 2) {
                        for (int d = 0; d < 4; d++) {
                            int ni = i + dx[d];
                            int nj = j + dy[d];
                            if (ni >= 0 && ni < rows && nj >= 0 && nj < cols && grid[ni][nj] == 1) {
                                grid[ni][nj] = 3;
                                changed = true;
                            }
                        }
                    }
                }
            }

            // Step 2: convert 3 → 2
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    if (grid[i][j] == 3) grid[i][j] = 2;
                }
            }

            // Step 3: if nothing changed, stop
            if (!changed) break;
            minutes++;
        }

        // Step 4: check for remaining fresh oranges
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1) return -1;
            }
        }

        return minutes;
    }
};
