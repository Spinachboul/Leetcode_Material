class Solution {
private:
    void BFS(int src, vector<vector<int>> &graph, vector<bool> &vis, set<int> &st){

        // set is used to store the component
        // vis[src] = true;
        queue<int> q;
        q.push(src);
        vis[src] = true;
        st.insert(src);
        while(!q.empty()){
            int currNode = q.front();
            q.pop();

            // then go through the neighbors of the queue
            for(auto& it: graph[currNode]){
                if(!vis[it]){
                    vis[it] = true;
                    st.insert(it);
                    q.push(it);
                    
                }
            }
        }
    }
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph;
        graph.resize(n);
        for(auto& it: edges){
            int u = it[0];
            int v = it[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        vector<bool> vis(n, false);

        // to store the number of connected components
        // vector<vector<int>> cc;
        int ans = 0;

        for(int i=0 ; i<n ; i++){
            if(!vis[i]){
                set<int> component;
                BFS(i, graph, vis, component);
                
                // check if the component formed is complete
                int k = component.size();
                // count the number of edges
                int expected = k * (k-1)/2;
                int actual = 0;
                for(int node: component){
                    actual += graph[node].size();
                    
                }

                actual /= 2; // each edge is actually counted twice in an adjacency list

                if(actual == expected){
                    // cc.push_back(vector<int> (component.begin() , component.end()));
                    ans++;
                }
            }
        }

        // return cc.size();
        return ans;



        
    }
};