class Solution {
public:
    int findLHS(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;

        for(int num : nums){
            mp[num]++;
        }        

        int mx = 0;
        for(auto& [num, count] : mp){
            if(mp.count(num+1)){
                int curr = count + mp[num+1];
                mx = max(mx, curr);
            }
        }

        return mx;

    }
};