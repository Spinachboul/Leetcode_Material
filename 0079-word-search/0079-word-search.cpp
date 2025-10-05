class Solution {
public:
    int m, n;
    vector<int> xdir = {0, 0, -1, 1};
    vector<int> ydir = {-1, 1, 0, 0};

    bool dfs(int i, int j, int index, vector<vector<char>>& board, string& word, vector<vector<bool>>& vis) {
        if (index == word.size()) return true; // all characters matched
        if (i < 0 || j < 0 || i >= m || j >= n) return false; // out of bounds
        if (vis[i][j] || board[i][j] != word[index]) return false; // invalid move

        vis[i][j] = true; // mark visited

        for (int d = 0; d < 4; d++) {
            int ii = i + xdir[d];
            int jj = j + ydir[d];

            if (dfs(ii, jj, index + 1, board, word, vis)) return true;
        }

        vis[i][j] = false; // backtrack
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, false));

        // Try starting from every cell
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (dfs(i, j, 0, board, word, vis)) {
                    return true;
                }
            }
        }

        return false;
    }
};
