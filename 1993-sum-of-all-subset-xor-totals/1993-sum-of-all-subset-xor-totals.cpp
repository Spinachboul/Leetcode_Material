class Solution {
private:
    void helper(int index, vector<int>& nums, vector<int> subset, vector<vector<int>> &ss){
        if(index == nums.size()){
            ss.push_back(subset);
            return;
        }

        subset.push_back(nums[index]);
        helper(index+1, nums, subset, ss);
        subset.pop_back();

        helper(index+1, nums, subset, ss);
    }
public:
    int subsetXORSum(vector<int>& nums) {    
        int n = nums.size();
        vector<vector<int>> ss;
        helper(0, nums, {}, ss);
        int res = 0;
        for(auto& subset: ss){
            int xorr = 0;
            for(int i=0 ; i<subset.size() ; i++){
                xorr ^= subset[i];
            }
            res += xorr;
        }
        return res;
        
    }
};