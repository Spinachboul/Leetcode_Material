class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int N = nums.size();
        sort(nums.begin() , nums.end());
        int i=0, j=N-1;
        vector<int> arr;
        while(i<j){
            int left = nums[i];
            int right = nums[j];
            arr.push_back(left + right);
            ++i;--j;
        }
        return *max_element(arr.begin() , arr.end());
        
    }
};