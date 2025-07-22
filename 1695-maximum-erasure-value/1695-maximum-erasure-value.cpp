class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st;
        int left  = 0;
        int currentSum = 0;
        int maxSum = 0;
        for(int i=0 ; i<n ; i++){
            while(st.find(nums[i]) != st.end()){
                currentSum -= nums[left];
                st.erase(nums[left]);
                left++;
            }

            currentSum += nums[i];
            st.insert(nums[i]);
            maxSum = max(maxSum, currentSum);
        }
        return maxSum;
        
    }
};