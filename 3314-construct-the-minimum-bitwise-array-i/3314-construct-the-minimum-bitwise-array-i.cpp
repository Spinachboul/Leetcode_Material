class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        for(int& x: nums){
            int d = 1;
            int res = -1;
            while((x & d) != 0){
                res = x - d;
                d <<= 1;
            }
            x = res;
        }
        return nums;

        
    }
};