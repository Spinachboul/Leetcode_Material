class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long ans = 0;
        unordered_map<int, int>mp;
        for(int i=0 ; i<nums.size() ; i++){
            int diff = i - nums[i];
            int gp = mp[diff];
            ans += i - gp;
            mp[diff] = gp+1;
        }
        return ans;

        
    }
};