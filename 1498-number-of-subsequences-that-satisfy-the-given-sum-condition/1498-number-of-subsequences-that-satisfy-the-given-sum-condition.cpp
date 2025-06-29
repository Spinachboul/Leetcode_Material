const int MOD = 1e9+7;
class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();
        int ans = 0;
        sort(nums.begin() , nums.end());
        vector<int> pow2mod(n+1, 1);
        for(int i=1 ; i<=n ; i++){
            pow2mod[i] = (pow2mod[i-1] << 1) % MOD;
        }
        int l = 0, r = n-1;
        while(l <= r){
            if(nums[l] + nums[r]<= target){
                ans = (ans + pow2mod[r-l]) % MOD;
                l++;
            }
            else r--;
        }
        return ans;
        
        
    }
};