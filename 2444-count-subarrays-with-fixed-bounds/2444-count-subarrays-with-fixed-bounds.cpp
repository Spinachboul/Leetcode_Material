# define ll long long
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n = nums.size();
        int left = 0;
        int x = -1, y = -1;
        ll count = 0;
        for(int i=0 ; i<n ; i++){
            if(nums[i] > maxK || nums[i] < minK){
            left = i+1;
            x = -1, y=-1;

            }
            else{
                if(nums[i] == minK) x = i;
                if(nums[i] == maxK) y = i;
                if(x != -1 && y != -1){
                    count += (ll) (min(x, y) - left +1);
                }
            }
        }
        return count;
        
    }
};