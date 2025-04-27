class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int count = 0;
        for(int right = 0 ; right < n ; right++){
            if(right - left+1 > 3) {
                left++;
            }
            if(right - left+1 == 3){
                int x = nums[right];
                int y = nums[left];
                int sum = 2*(x+y);
                if(sum == nums[left+1]) count++;
            }
        }
        return count;
        
    }
};