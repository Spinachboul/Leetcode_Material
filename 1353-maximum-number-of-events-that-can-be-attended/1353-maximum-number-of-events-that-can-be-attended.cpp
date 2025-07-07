class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int n = events.size();

        // first find max end time
        int maxDay = 0;
        for(int i=0 ; i<n;i++){
            maxDay = max(maxDay, events[i][1]);

        }
        sort(events.begin() , events.end());
        priority_queue<int, vector<int> , greater<>> pq;

        int ans = 0;
        for(int i=0, j=0; i<= maxDay; i++){
            while(j < n && events[j][0] <= i){
                pq.emplace(events[j][1]);
                j++;
            }
            while(!pq.empty() && pq.top() < i){
                pq.pop();
            }
            if(!pq.empty()){
                pq.pop();
                ans++;
            }

        }
        return ans;
        
    }
};