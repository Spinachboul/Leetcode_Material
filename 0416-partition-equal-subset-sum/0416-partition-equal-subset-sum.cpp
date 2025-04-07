class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin() , nums.end(), 0);
        if(sum & 1) return false;

        int targetSum = sum/2;

        bitset<10001> bit(1);
        for(auto& it: nums){
            bit |= bit << it;
            if(bit[sum/2]) return true;
        }
        return bit[sum/2];

        
    }
};