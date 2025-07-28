class Solution {
public:
    int func(vector<int>& nums, int index, int op, int tg, vector<vector<int>>& memo){
        if(index == nums.size()){
            return (op == tg) ? 1 : 0;

        }

        // check if the resulr of this state is already memoized
        if(memo[index][op] != -1) return memo[index][op];

        int cW = func(nums, index+1, op, tg, memo);
        int c = func(nums, index+1, op | nums[index], tg, memo);

        return memo[index][op] = c + cW;
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int n= nums.size();
        int mx = 0;
        for(int i=0 ; i<n ; i++){
            mx |= nums[i];
        }

        vector<vector<int>> memo(n,vector<int>(mx+1, -1));
        return func(nums, 0, 0, mx, memo);

        
        
    }
};