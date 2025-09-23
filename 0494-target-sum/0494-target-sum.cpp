class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = accumulate(nums.begin() , nums.end(), 0);

        if((sum + target)%2==1 || abs(target) > sum) return 0;
        int p = (sum + target) / 2;


        vector<int> dp(p+1, 0);
        dp[0] = 1;
        for(int num : nums){
            for(int i=p ; i>=num ; i--){
                dp[i] += dp[i - num];
            }
        }
        return dp[p];
        
    }
};