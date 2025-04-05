class Solution {
private:
    void generateSubsets(const vector<int> &nums,  int index, vector<int> subset, vector<vector<int>> &subsets){
        if(index == nums.size()){
            // we simply can add the subset to the subsets
            subsets.push_back(subset);
            return;
        }

        // generate subsets with nums[i]
        subset.push_back(nums[index]);
        generateSubsets(nums, index+1, subset, subsets);
        subset.pop_back();

        // generate subsets without nums[i];
        generateSubsets(nums, index+1, subset, subsets);
    }
public:
    int subsetXORSum(vector<int>& nums) {
        vector<vector<int>> subsets;
        // vector<int> subset;
        int index = 0;
        generateSubsets(nums, index, {}, subsets);

        // now for every subset, we need to find XOR total
        long long ans = 0;
        for(auto& subset: subsets){
            int total = 0;
            for(int num: subset){
                total ^= num;
            }
            ans += (long long)total;
        }
        return ans;
    }
};