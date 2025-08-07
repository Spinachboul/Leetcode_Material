#include <vector>
#include <tuple>
#include <map>
#include <set>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int n;
    vector<vector<int>> fruits;

    // Memoization map: (row1, row2, row3) at time t => max fruits
    map<tuple<int, int, int, int>, int> memo;

    // Movement directions for each child
    vector<pair<int, int>> movesA = {{1, 0}, {0, 1}, {1, 1}};     // A: ↓, →, ↘
    vector<pair<int, int>> movesB = {{1, 0}, {1, -1}, {1, 1}};    // B: ↓, ↙, ↘
    vector<pair<int, int>> movesC = {{0, 1}, {1, 1}, {-1, 1}};    // C: →, ↘, ↗

    // Checks if a cell is inside the grid
    bool isInside(int row, int col) {
        return row >= 0 && row < n && col >= 0 && col < n;
    }

    // Recursive DP function
    int dfs(int step, int rowA, int rowB, int rowC) {
        if (step == n) return 0;  // All kids have reached destination

        // Compute columns based on row and step
        int colA = step - rowA;
        int colB = step - rowB + n - 1;
        int colC = step - rowC;

        // If any position is out of bounds, return invalid path
        if (!isInside(rowA, colA) || !isInside(rowB, colB) || !isInside(rowC, colC))
            return INT_MIN;

        // Memoization key
        auto key = make_tuple(step, rowA, rowB, rowC);
        if (memo.count(key)) return memo[key];

        // Collect fruits at the 3 current positions (no double count)
        set<pair<int, int>> visited;
        visited.insert({rowA, colA});
        visited.insert({rowB, colB});
        visited.insert({rowC, colC});

        int collected = 0;
        for (auto [r, c] : visited)
            collected += fruits[r][c];

        int maxFruits = INT_MIN;

        // Try all 3 x 3 x 3 combinations of moves
        for (auto [drA, dcA] : movesA) {
            int nextRowA = rowA + drA;
            int nextColA = colA + dcA;

            for (auto [drB, dcB] : movesB) {
                int nextRowB = rowB + drB;
                int nextColB = colB + dcB;

                for (auto [drC, dcC] : movesC) {
                    int nextRowC = rowC + drC;
                    int nextColC = colC + dcC;

                    // Convert next rows back to time-relative positions
                    int nextStep = step + 1;
                    int result = dfs(nextStep, nextRowA, nextRowB, nextRowC);
                    if (result != INT_MIN)
                        maxFruits = max(maxFruits, collected + result);
                }
            }
        }

        return memo[key] = maxFruits;
    }

    int maxCollectedFruits(vector<vector<int>>& fruitsInput) {
        fruits = fruitsInput;
        n = fruits.size();

        // Start all kids at time 0
        // A: row 0 (col 0)
        // B: row 0 (col n-1)
        // C: row n-1 (col 0)
        return dfs(0, 0, 0, n - 1);
    }
};
