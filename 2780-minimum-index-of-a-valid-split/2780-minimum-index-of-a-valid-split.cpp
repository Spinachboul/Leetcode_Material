//brute force approach

class Solution {
private:
    bool isDominant(vector<int>& nums, int x){
        // get the frequency of the element
        int count = 0;
        for(int i=0 ; i<nums.size() ; i++){
            if(nums[i] == x) count++;
        }
        return count*2 >= nums.size();
    }
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mp;
        int dom = -1;
        // int ans = -1;

        for(int i=0 ; i<nums.size() ; i++){
            mp[nums[i]]++;
        }
        for(auto& it: mp){
            if(it.second*2 > nums.size()){
                dom = it.first;
                break;
            }
        }

        if(dom == -1) return -1;

        int leftCount = 0;
        for(int i=0 ; i+1 < nums.size() ; i++){
            if(nums[i] == dom) leftCount++;
            int leftSize = i+1;
            int rightSize = nums.size() - leftSize;
            int rightCount = mp[dom] - leftCount;

            if(leftCount*2 > leftSize && rightCount*2 > rightSize){
                return i;
            }

        }
        return -1;


        
    }
};