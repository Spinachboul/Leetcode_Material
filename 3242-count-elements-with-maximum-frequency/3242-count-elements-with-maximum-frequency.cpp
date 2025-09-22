class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int, int> mp;
        int mx = 1;
        for(int i=0 ; i<n ; i++){
            mp[nums[i]]++;
            mx = max(mx, mp[nums[i]]);
        }
        int ele = 0;
        for(auto& it: mp){
            if(it.second == mx) ele++;
        }
        return ele * mx;

    }
};