#include <vector>
#include <unordered_set>
#include <climits>
#include <algorithm>

using namespace std;

class Solution {
    int minRound = INT_MAX;
    int maxRound = 1;

public:
    vector<int> earliestAndLatest(int n, int firstPlayer, int secondPlayer) {
        if (firstPlayer > secondPlayer) {
            swap(firstPlayer, secondPlayer);
        }

        unordered_set<int> seen;
        dfs(n, 0, 1, firstPlayer, secondPlayer, seen);
        return {minRound, maxRound};
    }

private:
    void dfs(int n, int state, int round, int firstPlayer, int secondPlayer, unordered_set<int>& seen) {
        if (seen.count(state)) {
            return;
        }
        seen.insert(state);

        createPossibilities(n, 0, n - 1, state, round + 1, firstPlayer, secondPlayer, seen);
    }

    void createPossibilities(int n, int i, int j, int state, int round,
                             int firstPlayer, int secondPlayer, unordered_set<int>& seen) {
        while (i < j && ((state >> i) & 1)) i++;
        while (i < j && ((state >> j) & 1)) j--;

        if (i + 1 == firstPlayer && j + 1 == secondPlayer) {
            minRound = min(minRound, round - 1);
            maxRound = max(maxRound, round - 1);
            return;
        }

        if (i >= j) {
            dfs(n, state, round, firstPlayer, secondPlayer, seen);
        } else {
            int possibility1 = state | (1 << i);
            createPossibilities(n, i + 1, j - 1, possibility1, round, firstPlayer, secondPlayer, seen);

            int possibility2 = state | (1 << j);
            createPossibilities(n, i + 1, j - 1, possibility2, round, firstPlayer, secondPlayer, seen);
        }
    }
};
