class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        if(n<=1) return nums[0];
        vector<int> dp(n, 0);
        dp[0] = nums[0];
        int res = dp[0];
        for(int i=1 ; i<n ; i++){
            dp[i] = max(nums[i] , nums[i] + dp[i-1]);
            res = max(res, dp[i]);
        }
        return res;

        
    }
};