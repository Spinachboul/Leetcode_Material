class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int MOD = 1e9+7;
        vector<vector<pair<int, int>>> g(n);
        for(auto& it: roads){
            int startNode = it[0];
            int endNode = it[1];
            int time = it[2];
            g[startNode].emplace_back(endNode, time);
            g[endNode].emplace_back(startNode, time);
        }

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
        
        // to store the time to each node
        vector<long long> shortestTime(n, LLONG_MAX);

        vector<int> pathCount(n, 0);

        shortestTime[0] = 0; // distance to source is 0

        pathCount[0] = 1; // currently single way to reach node 0
        
        pq.emplace(0, 0);

        while(!pq.empty()){
            long long currTime = pq.top().first;

            int currNode = pq.top().second;
            pq.pop();

            if(currTime > shortestTime[currNode]) continue;

            for(auto& [node, roadTime]: g[currNode]){
                if(currTime + roadTime < shortestTime[node]){
                    shortestTime[node] = currTime + roadTime;
                    pathCount[node] = pathCount[currNode];

                    pq.emplace(shortestTime[node], node);
                }

                else if(currTime + roadTime == shortestTime[node]){
                    pathCount[node] = (pathCount[node] + pathCount[currNode]) % MOD;

                }

            }

        }
        return pathCount[n-1];

    }


};