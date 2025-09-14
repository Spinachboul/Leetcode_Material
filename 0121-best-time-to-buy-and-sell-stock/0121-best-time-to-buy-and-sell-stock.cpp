class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int mn = 99999;
        int mx = 0;
        for(int i : prices){
            mn = min(mn, i);
            mx = max(mx, i - mn);
        }
        return mx;


        
    }
};