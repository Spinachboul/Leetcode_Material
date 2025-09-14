class Solution {
private:
    bool isValid(int pos, vector<int>& nums, vector<int>& dp){
        if(dp[pos] != -1) return dp[pos];

        for(int i=pos-1 ; i>=0 ; i--){
            if(isValid(i, nums, dp) && nums[i] >= (pos-i)){
                dp[pos] = 1;
                return dp[pos];
            }
        }
        dp[pos] = 0;
        return dp[pos];
    }
public:
    bool canJump(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        dp[0] = 1;
        return isValid(nums.size()-1, nums, dp);
    }
};