#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    unordered_map<int, int> bobMap;  // To store the time Bob reaches each node
    vector<int> vis;                 // Replaced vector<bool> with vector<int>
    vector<vector<int>> tree;

    // Function to find Bob's path to the root and record the time he reaches each node
    bool findBobPath(int sourceNode, int time) {
        bobMap[sourceNode] = time;
        vis[sourceNode] = 1;  // Mark as visited

        if (sourceNode == 0) return true;  // Reached root

        for (auto& it : tree[sourceNode]) {
            if (!vis[it]) {
                if (findBobPath(it, time + 1)) {
                    return true;
                }
            }
        }

        // Backtrack if root not reached through this path
        bobMap.erase(sourceNode);
        return false;
    }

public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = amount.size();
        int ans = INT_MIN;
        tree.resize(n);
        
        // Build the tree from edges
        for (auto& it : edges) {
            int x = it[0];
            int y = it[1];
            tree[x].push_back(y);
            tree[y].push_back(x);
        }

        // Initialize visited vector
        vis.assign(n, 0);
        
        // Find Bob's path and mark times
        findBobPath(bob, 0);

        // Reset visited for Alice's BFS
        vis.assign(n, 0);
        
        // BFS for Alice
        queue<vector<int>> q;
        q.push({0, 0, 0});  // {currentNode, time, income}
        vis[0] = 1;

        while (!q.empty()) {
            auto curr = q.front();
            q.pop();

            int sourceNode = curr[0];
            int time = curr[1];
            int income = curr[2];

            // Case 1: Alice reaches first
            if (bobMap.find(sourceNode) == bobMap.end() || time < bobMap[sourceNode]) {
                income += amount[sourceNode];
            }
            // Case 2: Alice and Bob reach at the same time
            else if (time == bobMap[sourceNode]) {
                income += (amount[sourceNode]) / 2;
            }
            // Case 3: Bob reaches first → Alice gets nothing

            // Check if it's a leaf node (excluding root)
            if (tree[sourceNode].size() == 1 && sourceNode != 0) {
                ans = max(ans, income);
            }

            // Explore neighbors
            for (auto& it : tree[sourceNode]) {
                if (!vis[it]) {
                    vis[it] = 1;  // Mark visited when pushing into queue
                    q.push({it, time + 1, income});
                }
            }
        }

        return ans;
    }
};
