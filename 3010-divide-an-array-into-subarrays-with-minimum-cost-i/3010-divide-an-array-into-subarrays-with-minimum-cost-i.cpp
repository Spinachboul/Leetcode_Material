class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int n = nums.size();
        vector<int> suffix(n);
        suffix[n-1]= nums[n-1];
        for(int i=n-2 ; i>=0 ; i--){
            suffix[i] = min(nums[i] , suffix[i+1]);
        }

        int ans = INT_MAX;
        for(int i=1 ; i<n-1 ; i++){
            int cost = nums[0] + nums[i] + suffix[i+1];
            ans = min(ans, cost);

        }
        return ans;
        
    }
};