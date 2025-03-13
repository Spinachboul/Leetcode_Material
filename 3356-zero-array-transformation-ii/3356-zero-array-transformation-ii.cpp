class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int left = 0,  right = queries.size();

        if(!canFormZeroArray(nums, queries, right)) return -1;

        while(left <= right){
            int mid = left + (right - left)/2;
            if(canFormZeroArray(nums, queries, mid)){
                right = mid-1;
            }
            else left = mid + 1;
        }
        // return earliest query that zero array can be formed
        return left;

        
    }
private:    
    bool canFormZeroArray(vector<int> &nums, vector<vector<int>> &queries, int k){
        int n = nums.size();
        int sum = 0;
        vector<int> differenceArray(n+1, 0);

        for(int i = 0 ; i < k ; i++){
            int start = queries[i][0];
            int end = queries[i][1];
            int val = queries[i][2];

            // processs start and end of the range
            differenceArray[start]+= val;
            differenceArray[end+1] -= val;

            

        }
        // check if zero array can be formed
        for(int j=0 ; j<n ; j++){
            sum += differenceArray[j];
            if(sum < nums[j]) return false;
        }
        return true;
    }
};