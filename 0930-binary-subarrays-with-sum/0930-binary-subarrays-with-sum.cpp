class Solution {
public:
    // sum with atmost k value
    int fun(vector<int> &nums, int k){
        if(k < 0) return 0;
        int left = 0, right =0, sum = 0;
        int count = 0;
        while(right < nums.size()){
            sum += nums[right];
            while(sum > k){
                sum -= nums[left];
                left++;
            }
            count += right - left + 1;
            right++;
        }
        return count;
    }
    // sum with atmost k value - sum with atmost k-1 value
    // sum with exactly k value
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return fun(nums, goal) - fun(nums, goal-1);
        
    }
};