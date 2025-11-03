class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int ans = 0;
        for(int i=1 ; i<colors.size() ; i++){
            if(colors[i] == colors[i-1]){
                int mn = min(neededTime[i] , neededTime[i-1]);
                ans += mn;
                neededTime[i] = max(neededTime[i] , neededTime[i-1]);
            }
        }
        return ans;
        
    }
};