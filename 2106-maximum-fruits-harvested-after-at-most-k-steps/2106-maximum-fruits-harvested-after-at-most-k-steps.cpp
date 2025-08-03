class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int sp, int k) {
        int n = fruits.size();
        //atmost k steps
        // collect maximum fruits
        // greedy

        vector<int> sum(n+1); // this is the cumumlative array
        vector<int> indices(n); 

        for(int i=0 ; i<n ; i++){
            // fruits[i][1] gets you the amount
            sum[i+1] = sum[i] + fruits[i][1];
            indices[i] = fruits[i][0];
        }
        int ans = 0;
        for(int x = 0 ; x<=k/2 ; x++){
            int y = k-2*x;
            int left = sp-x;
            int right = sp + y;
            int ss = lower_bound(indices.begin() , indices.end(), left) - indices.begin();
            int ee = upper_bound(indices.begin() , indices.end() , right) - indices.begin();
            ans = max(ans, sum[ee] - sum[ss]);

            y = k - 2*x;
            left = sp-y;
            right = sp + x;
            ss = lower_bound(indices.begin() , indices.end(), left) - indices.begin();// first value whivh is smaller than the given value
            ee = upper_bound(indices.begin() , indices.end() , right) - indices.begin(); // first value wich is greater than the given value
            ans = max(ans, sum[ee] - sum[ss]);
        }
        return ans;

        



        
        
    }
};