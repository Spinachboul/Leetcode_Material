class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int n = nums.size();

        vector<vector<int>> dp(k, vector<int> (k, 0));
        int res = 0;
        for(int num : nums){
            num = num % k;

            for(int j=0 ; j<k ; j++){
                dp[j][num] = dp[num][j] + 1;
                res = max(res, dp[j][num]);
            }
        }
        return res;
        
    }
};