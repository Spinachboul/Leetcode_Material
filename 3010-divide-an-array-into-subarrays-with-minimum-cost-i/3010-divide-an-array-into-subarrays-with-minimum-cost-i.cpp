class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int n = nums.size();
        int mn =INT_MAX;
        for(int i=1 ; i<n-1 ; i++){
            for(int j=i+1 ; j<n ; j++){
                mn = min(mn, nums[0] + nums[i] + nums[j]);
            }
        }

        return mn;
        
    }
};