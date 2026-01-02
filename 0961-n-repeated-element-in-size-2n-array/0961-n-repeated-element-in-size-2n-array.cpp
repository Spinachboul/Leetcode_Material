class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int N = n/2;

        unordered_map<int, int> mp;
        for(int i=0 ; i<n ; i++){
            mp[nums[i]]++;
        }

        for(auto& it: mp){
            int freq = it.second;
            if(freq == N){
                return it.first;
            }
        }

        return -1;


        
    }
};