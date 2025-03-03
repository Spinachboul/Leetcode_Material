class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        // this is for restoring the original order of the elements
        vector<int> before, after;
        int count = 0;
        for(int i=0 ; i<nums.size() ; i++){
            if(nums[i] < pivot){
                before.push_back(nums[i]);
            }
            else if(nums[i] > pivot){
                after.push_back(nums[i]);

            }
            else count++;
        }

        // construct the answer;
        vector<int> ans;
        // first push back the smaller elements

        ans.insert(ans.end(), before.begin(), before.end());
        while(count>0){
            ans.push_back(pivot);
            count--;
        }
        ans.insert(ans.end(), after.begin(), after.end());

        return ans;



        
    }
};