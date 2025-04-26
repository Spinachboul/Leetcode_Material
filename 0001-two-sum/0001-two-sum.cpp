class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> mp;
        for(int i=0 ; i<n ; i++){
            mp[nums[i]] = i;
        }
        for(int i=0 ; i<n ; i++){
            int curr = nums[i];
            int toFind = target - curr;
            if(mp.count(toFind) && mp[toFind] != i){
                return {i, mp[toFind]};
            }
            mp[curr] = i;
        }
        return {};
    }
};