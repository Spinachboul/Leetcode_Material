class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        sort(nums.begin() , nums.end());
        int ans = 1, currlen = 1;
        for(int i=1 ; i<n ; i++){
            if(nums[i] == nums[i-1]){
                continue;
            }
            else if(nums[i] == nums[i-1] + 1){
                currlen++;
                ans = max(ans, currlen);
            }
            else{
                currlen = 1;
            }
        }
        return ans;
        
    }
};