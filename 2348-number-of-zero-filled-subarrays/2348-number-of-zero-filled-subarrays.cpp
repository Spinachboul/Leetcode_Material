class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans = 0, streak = 0;
        for(int num : nums){
            if(num == 0){
                streak++;
                ans += streak;
            }
            else{
                streak = 0;

            }

        }
        return ansl

        
    }
};