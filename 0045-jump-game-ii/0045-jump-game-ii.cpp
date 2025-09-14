class Solution {
private:
    long long int jump(int curr, int dest, vector<int> &nums, vector<int> &dp){
        // base case
        if(curr == dest) return 0;
        if(dp[curr] != -1) return dp[curr];
        long long int temp = INT_MAX;

        for(int i=1 ; i<=nums[curr] ; i++){
            if(i + curr > dest) break;
            temp = min(temp, 1 + jump(curr + i, dest, nums, dp));
        }
        dp[curr] = temp;
        return temp;
    }
public:
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return jump(0, nums.size()-1, nums, dp);
    }
};