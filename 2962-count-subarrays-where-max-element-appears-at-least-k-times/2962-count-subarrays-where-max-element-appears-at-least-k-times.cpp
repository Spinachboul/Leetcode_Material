class Solution { 
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxElement = *max_element(nums.begin() , nums.end());
        long long ans = 0;
        int start = 0;
        int inWindow = 0;
        int n = nums.size();
        for(int right = 0;  right < n;right++){
            if(nums[right] == maxElement){
                inWindow++;
            }
            while(inWindow == k){
                if(nums[start] == maxElement){
                    inWindow--;
                }
                start++;
            }
            ans += start;
        }
        return ans;
        
       
    }
};