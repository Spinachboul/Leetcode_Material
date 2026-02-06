class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n = nums.size();
        if(n==1) return 0;

        sort(nums.begin() , nums.end());
        int ans = 0;
        int i=0;
        for(int j=0 ; j<n ; j++){
            while((long long)nums[j] > (long long)nums[i] * k){
                i++;
            }

            ans = max(j - i + 1 , ans);
        }

        return n - ans;



        

    }
};