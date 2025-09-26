class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int actual = (nums.size() * (nums.size() +1))/2;

        int currSum = accumulate(nums.begin() , nums.end() , 0);

        return actual - currSum;


        
    }
};