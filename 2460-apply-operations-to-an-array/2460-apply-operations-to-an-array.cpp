class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();
        for(int i=0 ; i+1<n ; i++){
            if(nums[i] == nums[i+1]){
                nums[i] *= 2;
                nums[i+1] = 0;
            }
        }

        vector<int> temp = nums;
        int j=0;
        for(int i=0 ; i<n ; i++){
            if(nums[i]!=0){
                temp[j++] = nums[i];
            }
        }
        while(j<n){
            temp[j++] = 0;
        }
        return temp;

        
    }
};