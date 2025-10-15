class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();
        int count = 1 , prev = 0;
        int ans = 0;

        for(int i=1 ; i<n ; i++){
            if(nums[i] > nums[i-1]){
                ++count;
            }
            else{
                prev = count;
                count = 1;
            }
            ans = max(ans, count/2);

            ans = max(ans, min(prev, count));
            
        }
        return ans;

        
    }
};