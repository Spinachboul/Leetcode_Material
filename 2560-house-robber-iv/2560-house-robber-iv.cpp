class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        int n = nums.size();

        int mn = 1, mx = *max_element(nums.begin() , nums.end());
        while(mn < mx){
            int mid = mn + (mx - mn)/2;
            int possibleThefts = 0;

            for(int i=0 ; i<n ; i++){
                if(nums[i] <= mid){
                    possibleThefts +=1 ;
                    i++;
                }
            }

            if(possibleThefts >= k){
                mx = mid;
            }
            else mn = mid +1;
        }

        return mn;

        
    }
};