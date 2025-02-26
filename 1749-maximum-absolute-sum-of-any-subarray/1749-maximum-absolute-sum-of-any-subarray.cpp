class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();
        int mxSum = 0;
        // for(int i=0 ; i<n ; i++){
        //     nums[i] = abs(nums[i]);
        // }

        vector<int> prefix(n+1, 0);
        int mx = 0, mn = 0, ans = 0;
        for(int i=0 ; i<n ; i++){
            prefix[i+1] = prefix[i] + nums[i];
            mx = max(mx, prefix[i+1]);
            mn = min(mn, prefix[i+1]);
            ans = max(ans,  abs(mx - mn));

        }
        return ans;

        
    }
};