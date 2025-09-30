class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n = nums.size();
        

        while(nums.size() > 1){
            vector<int> newNum(nums.size() - 1);
            for (int i = 0; i < newNum.size(); i++) {
                newNum[i] = (nums[i] + nums[i + 1]) % 10;
            }
            nums = newNum;


        }
        return nums[0];
    }
};